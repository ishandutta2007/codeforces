#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4050,mod=998244353;
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
ll jc[maxn],ny[maxn];
int i,j,k,n,m;
ll C(int x,int y){
    if(y<0 || y>x)return 0;
    return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
    jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
    ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    cin>>n>>m;
    ll Ans=0;
    for(int X=1;X<=m;X++){
        ll S1=0,S2=0;
        for(int B=1;B<=n;B++)S2+=C(B-1+m-X,B-1)%mod*C(n-B+m-X-1,n-B)%mod,S2%=mod;
        for(int A=1;A<=n;A++){
            int B=n-A+1;
            S1=C(A-1+X,A-1)*C(n-A+X-1,n-A)%mod;
            S2+=mod-C(B-1+m-X,B-1)*C(n-B+m-X-1,n-B)%mod;
            S1%=mod;S2%=mod;
            Ans+=S1*S2%mod;
        }Ans%=mod;
    }

    // C(m-X,m-X)*C(n-1+m-X-1,m-X-1) + C(m-X+1,m-X)*C(n-2+m-X-1,m-X-1) + .. + C(n-A+1+m-X,m-X-1)*C(A+m-X-1,m-X-1)

    for(int X=1;X<=n;X++){
        ll S1=0,S2=0;
        for(int B=1;B<m;B++)S2+=C(B-1+n-X,n-X)*C(m-B+n-X-1,n-X-1)%mod,S2%=mod;
        for(int A=1;A<m;A++){
            int B=m-A;
            S1=C(A-1+X,X)*C(m-A+X-1,X-1)%mod;
            S2+=mod-C(B-1+n-X,n-X)*C(m-B+n-X-1,n-X-1)%mod;
            S1%=mod;S2%=mod;
            Ans+=S1*S2%mod;
        }Ans%=mod;
    }cout<<Ans*2%mod<<endl;
}