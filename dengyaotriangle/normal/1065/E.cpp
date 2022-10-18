#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const long long mdn=998244353;

int m;
long long n,s;
long long b[maxn];

inline long long ksm(long long bse,long long ex){
    if(ex==0) return 1;
    if(ex==1) return bse%mdn;
    long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1) ans=(ans*bse)%mdn;
    return ans;
}

long long i2;

int main(){
    i2=ksm(2,mdn-2);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    reverse(b+1,b+1+m);
    long long ans=ksm(s,(n-(b[1]<<1)));
    for(int i=2;i<=m+1;i++){
        long long t1=ksm(s,b[i-1]-b[i]),t2=(t1*t1)%mdn;
        long long dtk=(t2-t1+mdn)%mdn;
        dtk=(dtk*i2)%mdn;
        ans=(ans*(dtk+t1))%mdn;
    }
    cout<<ans;
    return 0;
}