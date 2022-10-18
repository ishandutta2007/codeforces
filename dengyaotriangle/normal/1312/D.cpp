#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
constexpr int mdn=998244353;
constexpr int inv2=(mdn+1)/2;
template<int mdn>inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int fac[maxn],ifac[maxn];

int n,m;

inline int binom(int n,int m){
    if(n<0||m>n||m<0)return 0;
    return fac[n]*(long long)ifac[m]%mdn*ifac[n-m]%mdn;
}

int main(){
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*(long long)i%mdn;
    ifac[maxn-1]=qpw<mdn>(fac[maxn-1],mdn-2);
    for(int i=maxn-1;i>0;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;
    cin>>n>>m;
    if(n<3){cout<<0;return 0;}
    int cof=binom(m,n-1)*(long long)(n-2)%mdn;
    for(int i=1;i<=n-3;i++)cof=(cof<<1)%mdn;
    cout<<cof;
    return 0;
}