#include<bits/stdc++.h>

using namespace std;

const int maxk=1000006;
const long long mdn=1000000007;

long long n;
int k;
long long cy[maxk];
long long pfx[maxk],sfx[maxk];
long long jc[maxk];
long long ijc[maxk];

inline long long calc(long long i){
    if(i==0) return sfx[1];
    return (pfx[i-1]*sfx[i+1])%mdn;
}
inline long long ca1c(long long i){
    if((k+1-i)&1) return (mdn- ((ijc[i]*ijc[k+1-i])%mdn))%mdn;
    else return (ijc[i]*ijc[k+1-i])%mdn;
}
long long ksm(long long bse,long long ex){
    if(ex==0) return 1;
    if(ex==1) return bse%mdn;
    long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1)ans=(ans*bse)%mdn;
    return ans;
}

int main(){
    cin>>n>>k;
    cy[0]=0;
    for(int i=1;i<=k+1;i++){
        cy[i]=(cy[i-1]+ksm(i,k))%mdn;
    }
    if(n<=k+1){
        cout<<cy[n];
        return 0;
    }
    jc[0]=1;
    for(int i=1;i<=k+1;i++) jc[i]=(jc[i-1]*i)%mdn;
    ijc[k+1]=ksm(jc[k+1],mdn-2);
    for(int i=k;i>=0;i--){
        ijc[i]=(ijc[i+1]*(i+1))%mdn;
    }
    long long ans=0;
    pfx[0]=n;
    for(int i=1;i<=k+1;i++) pfx[i]=(pfx[i-1]*(n-i))%mdn;
    sfx[k+2]=1;
    for(int i=k+1;i>=1;i--) sfx[i]=(sfx[i+1]*(n-i))%mdn;
    for(int i=0;i<=k+1;i++){
        long long cur=cy[i];
        cur*=calc(i);cur%=mdn;
        cur*=ca1c(i);cur%=mdn;
        ans=(ans+cur)%mdn;
    }
    cout<<ans;
    return 0;
}