#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
const int maxp=1000005;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
template<typename t> t rndi(t lb,t ub){return rng()%(ub-lb+1)+lb;}

int n;
long long a[maxn];
int prm[maxp],prc;
bool ntp[maxp];
void seive(){
    for(int i=2;i<maxp;i++){
        if(!ntp[i]){
            prm[++prc]=i;
        }
        for(int j=1;i*prm[j]<maxp;j++){
            ntp[i*prm[j]]=1;
            if(!(i%prm[j]))break;
        }
    }
}
inline long long gans(long long div){
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=div)ans+=min(a[i]%div,div-a[i]%div);
        else ans+=div-a[i];
    }
    //cerr<<div<<":"<<ans<<endl;
    return ans;
}
inline void calc(long long x,long long&ans){
    if(x==0)return;
    for(int i=1;i<=prc;i++){
        if(x%prm[i]==0){
            ans=min(ans,gans(prm[i]));
            while(x%prm[i]==0)x/=prm[i];
        }
    }
    if(x!=1)ans=min(ans,gans(x));
}
int main(){
    seive();
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];}
    long long ans=n;
    for(int t=0;t<20;t++){
        int id=rndi(1,n);
        calc(a[id],ans);
        calc(a[id]-1,ans);
        calc(a[id]+1,ans);
    }
    cout<<ans;
    return 0;
}