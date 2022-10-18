#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=500005;

int n;
int a[maxn];
int p[maxn];
int id[maxn];
long long wl[maxn],wr[maxn];
int m,b[maxn];

template<typename t,int sz> struct bita{
    static const int bmaxn=sz;t val[bmaxn];bita(){memset(val,0,sizeof(val));}
    inline void chg(int i,t v){while(i<bmaxn){val[i]+=v;i+=i&(-i);}}inline t qry(int i){t ans=0;while(i){ans+=val[i];i-=i&(-i);}return ans;}
};
bita<long long,maxn> bit,bitn;
long long dp[maxn],df[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>p[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=m;i++)id[b[i]]=i;
    for(int i=1;i<=n;i++){
        if(id[a[i]]){
            int pt=b[id[a[i]]-1];
            wr[i]=bit.qry(maxn-1)-bit.qry(pt)+bitn.qry(pt);
        }
        bit.chg(a[i],p[i]);
        if(p[i]<0)bitn.chg(a[i],p[i]);
        if(id[a[i]]){
            wl[i]=bit.qry(maxn-1)-bit.qry(a[i])+bitn.qry(a[i]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    memset(df,0x3f,sizeof(df));
    dp[0]=df[0]=0;
    for(int i=1;i<=n;i++){
        if(id[a[i]]&&df[id[a[i]]-1]!=0x3f3f3f3f3f3f3f3f){
            dp[i]=wr[i]+df[id[a[i]]-1];
            df[id[a[i]]]=min(df[id[a[i]]],dp[i]-wl[i]);
        }
    }
    if(df[m]==0x3f3f3f3f3f3f3f3f)cout<<"NO";
    else cout<<"YES\n"<<df[m]+bit.qry(maxn-1)-bit.qry(b[m])+bitn.qry(b[m]);
    return 0;
}