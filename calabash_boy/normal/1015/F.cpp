#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL mod = 1e9+7;
const int maxn = 205;
LL dp[maxn][maxn][maxn];
char s[maxn];
int n;
struct KMP{
    int nxt[maxn];
    int len;
    void clear(){
        len =0;
        nxt[0] = nxt[1] =0;
    }
    /* 1-bas */
    /* ss\0 */
    void init(char* ss){
        len = strlen(ss+1);
        for (int i=2;i<=len;i++){
            nxt[i] = nxt[i-1];
            while (nxt[i]&&ss[i]!=ss[nxt[i]+1]) nxt[i] = nxt[nxt[i]];
            nxt[i]+=(ss[i]==ss[nxt[i]+1]);
        }
    }
    void proc(){
        for (int i=len;i>=2;i--){
            char ch='(';
            if (s[i]=='('){
                ch = ')';
            }
            nxt[i] = nxt[i-1];
            while (nxt[i]&&s[nxt[i]+1]!=ch)nxt[i] = nxt[nxt[i]];
            if (s[nxt[i]+1]==ch)nxt[i]++;
        }
    }
    void debug(){
        for (int i=0;i<=len;i++){
            printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
//            Debug(nxt[i]);
        }
    }
    /*   acaca  ac  */
    vector<int> periodic(){
        vector<int> ret;
        int now = len;
        while (now){
            now = nxt[now];
            ret.push_back(len-now);
        }
        return ret;
    }
    /*   acac acacacaca*/
    vector<int> periodic_loop(){
        vector<int>ret ;
        for (int x :periodic()){
            if (len%x==0){
                ret.push_back(x);
            }
        }
        return ret;
    }
    int min_periodic_loop(){
        return periodic_loop()[0];
    }
}kmper;
inline void add(LL&x,LL&y){
    x = (x+y)%mod;
}
LL power(LL x,LL y){
    LL res =1;
    while (y){
        if (y&1){
            res = res*x%mod;
        }
        y>>=1;
        x = x*x%mod;
    }
    return res;
}
LL fac(int n){
    LL res =1;
    for (int i=2;i<=n;i++){
        res = res*i%mod;
    }
    return res;
}
LL C(int x,int y){
    return fac(x)*power(fac(y),mod-2)%mod*power(fac(x-y),mod-2)%mod;
}
LL catlan(int n){
    return C(2*n,n)*power(n+1,mod-2)%mod;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    int m = strlen(s+1);
    kmper.init(s);
    kmper.proc();
    //kmper.debug();
    dp[0][0][0]=1;
    for (int i=0;i<=2*n-1;i++){
        for (int j=0;j<m;j++){
            for (int k=0;k<=n;k++){
                // i index j same k presum
                //(
                int kk = k+1;
//                int jj=j;
                if (kk<=n)
                if (s[j+1]=='('){
                    int jj = j+1;
                    add(dp[i+1][jj][kk],dp[i][j][k]);
                }else{
                    int jj = kmper.nxt[j+1];
                    add(dp[i+1][jj][kk],dp[i][j][k]);
                }
                //)
                kk = k-1;
                if (k>=0)
                if (s[j+1]==')'){
                    int jj = j+1;
                    add(dp[i+1][jj][kk],dp[i][j][k]);
                }else{
                    int jj = kmper.nxt[j+1];
                    add(dp[i+1][jj][kk],dp[i][j][k]);
                }
            }
        }
    }

    LL ans =0;
    for (int i=0;i<m;i++){
        add(ans,dp[2*n][i][0]);
    }
   // cout<<ans<<endl;
    cout<<(catlan(n)-ans+mod)%mod<<endl;
}