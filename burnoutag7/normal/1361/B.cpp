#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1000000007;

ll qpow(ll a,ll n){
    ll res=1;
    while(n){
        if(n&1)res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

int n,p;
int k[1000005];
bool big;
ll g,a,ans;

int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&p);
        for(int i=1;i<=n;i++)scanf("%d",k+i);
        sort(k+1,k+1+n);
        reverse(k+1,k+1+n);
        big=g=ans=0;
        a=k[1];
        k[n+1]=0;
        for(int i=1;i<=n;i++){
            if(big||g>0){
                g--;
                ans=(ans-qpow(p,k[i])+mod)%mod;
            }else{
                g++;
                ans=(ans+qpow(p,k[i]))%mod;
            }
            if(p==1||g==0){
                a=k[i+1];
                continue;
            }
            if(a-k[i+1]>=20){
                big=1;
                continue;
            }
            while(a>k[i+1]){
                g*=p;
                a--;
                if(g>n)big=1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}