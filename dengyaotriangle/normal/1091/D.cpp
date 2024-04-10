#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1000005;
const long long mdn=998244353;

int n;
long long fac[maxn];

long long ksm(long long bse,int ex){
    if(ex==0)return 1;
    long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1)ans=(ans*bse)%mdn;
    return ans;
}
int main(){
    cin>>n;
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%mdn;
    long long ans=(n*fac[n])%mdn;
    for(int i=1;i<n;i++){
        //cerr<<(fac[n]*ksm(fac[i],mdn-2))%mdn<<endl;
        ans+=(mdn-(fac[n]*ksm(fac[i],mdn-2))%mdn);
        ans%=mdn;
    }
    cout<<ans;
    return 0;
}