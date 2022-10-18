#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=1000000007;
const int maxn=2e5+3;
const int inv2=(mdn+1)/2;


int fac[maxn],ifac[maxn];
int inv(int x){return x==1?1:inv(mdn%x)*(long long)(mdn-mdn/x)%mdn;}
int main(){
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*(long long)i%mdn;
    ifac[maxn-1]=inv(fac[maxn-1]);
    for(int i=maxn-1;i>=1;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ans=1;
        for(int i=1;i<=n;i++){
            int tot=n-(i-1)*(k-1)-i;
            int p=ifac[n]*(long long)fac[i]%mdn*fac[n-i]%mdn;
            if(tot>=0){
                ans=(ans+p*(long long)fac[tot+i]%mdn*ifac[tot]%mdn*ifac[i])%mdn;
            }else break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}