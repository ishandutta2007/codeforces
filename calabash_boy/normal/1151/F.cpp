#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
const int mod = 1e9 + 7;
struct Matrix{
    int val[maxn][maxn];
    int height,width;
    Matrix(int h,int w){
        height = h;
        width = w;
        memset(val,0,sizeof val);
    }
    Matrix operator *(const Matrix& other)const{
        assert(width == other.height);
        Matrix ret(height,other.width);
        for (int i=1;i<=height;i++){
            for (int j=1;j<=other.width;j++){
                for (int k = 1;k <= width;k++){
                    (ret.val[i][j] += 1ll *val[i][k] * other.val[k][j]% mod)%= mod;
                }
            }
        }
        return ret;
    }
    void print(){
        for (int i=1;i<=height;i++){
            for (int j=1;j<=width;j++){
                printf("%d ",val[i][j]);
            }
            puts("");
        }
    }
};
int C[maxn][maxn];
int n,k;
int a[maxn];
int ans[maxn];
int powmod(int x,int y){
    int res = 1;
    while (y){
        if (y&1){
            res = 1ll * res * x % mod;
        }
        y >>= 1;
        x = 1ll * x * x % mod;
    }
    return res;
}
Matrix powmod(Matrix trans,int y){
    Matrix res(trans.height,trans.width);
    for (int i=1;i<=trans.height;i++){
        res.val[i][i] = 1;
    }
    while (y){
        if (y&1){
            res = res * trans;
        }
        y >>= 1;
        trans = trans * trans;
    }
    return res;
}
int main(){
    C[0][0] = 1;
    for (int i=1;i<maxn;i++){
        C[i][0] = C[i][i] = 1;
        for (int j=1;j<i;j++){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
    scanf("%d%d",&n,&k);
    int cnt0 = 0;
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
        cnt0 += a[i] == 0;
    }
    int my0 = 0;
    for (int i=1;i<=cnt0;i++){
        my0 += a[i] == 0;
    }
    Matrix trans(cnt0+1,cnt0+1);
    for (int i=0;i<=cnt0;i++){
        if (cnt0 - i > n - cnt0)continue;
        if (i-1 >=0 && cnt0 - i + 1 <= n - cnt0){
            trans.val[i+1][i] = 1ll * (cnt0 - i +1) * (cnt0 - i+1) % mod;
        }
        trans.val[i+1][i+1] = 1ll * (C[cnt0][2] + C[n-cnt0][2]+ 1ll * i * (cnt0 - i) % mod + 1ll * (cnt0 - i) * (n - 2 * cnt0 + i) % mod)% mod;
        /*
        if (n - 2 * cnt0 + i>0){
            (trans.val[i+1][i+1] +=1ll * (cnt0 - i) * (n - 2 * cnt0 + i) % mod)%= mod;
        }
        */
        if (i+1 <=cnt0 && n - 2 * cnt0 + i+1>0){
            trans.val[i+1][i+2] = 1ll * (i+1) * (n - 2 * cnt0 + i+1) % mod;
        }
    }
    //trans.print();
    Matrix final_trans = powmod(trans,k);
    //final_trans.print();
    for (int i=1;i<=cnt0+1;i++){
        ans[i-1] = final_trans.val[i][my0+1];
    }
    int p = ans[cnt0],q = 0;
    for (int i=0;i<=cnt0;i++){
        (q += ans[i])%= mod;
    }
    //cout<<p<<" "<<q<<endl;
    cout<< 1ll * p * powmod(powmod(C[n][2],k),mod-2) % mod<<endl;
    return 0;
}