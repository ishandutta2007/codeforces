#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=998244353;
const int maxn=200005;

inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int n,k;
int fac[maxn],ifac[maxn];
inline int binom(int n,int m){return fac[n]*(long long)ifac[m]%mdn*ifac[n-m]%mdn;}
int main(){
    cin>>n>>k;
    if(k>n){cout<<0;return 0;}
    k=n-k;
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]*(long long)i%mdn;
    ifac[n]=qpw(fac[n],mdn-2);
    for(int i=n;i>0;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;
    int ans=0;
    for(int i=0;i<=k;i++){
        int cur=binom(k,k-i)*(long long)qpw(k-i,n)%mdn;
        if(i&1)ans+=mdn-cur;
        else ans+=cur;
        if(ans>=mdn)ans-=mdn;
    }
    ans=ans*(long long)binom(n,k)%mdn;
    if(k!=n){ans<<=1;if(ans>=mdn)ans-=mdn;}
    cout<<ans;
    return 0;
}