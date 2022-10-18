#include<bits/stdc++.h>

using namespace std;

const long long mdn=1000000007;
const int maxk=105;

struct mat{
    long long v[maxk][maxk];
};

mat mult(mat a,mat b){
    mat c;memset(c.v,0,sizeof(c.v));
    for(int k=0;k<maxk;k++){
        for(int i=0;i<maxk;i++){
            for(int j=0;j<maxk;j++){
                c.v[i][j]+=a.v[i][k]*b.v[k][j];
                c.v[i][j]%=mdn;
            }
        }
    }
    return c;
}

mat ksm(mat a,long long ex){
    if(ex==1) return a;
    mat ans=ksm(a,ex>>1);ans=mult(ans,ans);
    if(ex&1) ans=mult(ans,a);
    return ans;
}

mat dp;
int main(){
    long long n,m;
    cin>>n>>m;
    dp.v[0][0]=1;
    dp.v[0][m-1]=1;
    for(int i=1;i<=m-1;i++) dp.v[i][i-1]=1;
    mat ans=ksm(dp,n);
    cout<<ans.v[0][0];
    return 0;
}