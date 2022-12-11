#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,int>
#define mkp make_pair
using namespace std;
const int mod=1e9+7,N=1e5+50;
int n,m,seed,vmax,cnt;
pii b[N];
map<int,LL>mp;
map<int,LL>::iterator it,jt;
int rnd(){
    int ret=seed;
    seed=(7ll*seed+13)%mod;
    return ret;
}
void split(int x){
    if(mp.count(x))return;
    it=--mp.upper_bound(x);
    mp[x]=it->second;
}
int power(int x,int y,int mod){
    int z=1;
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
    return z;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&seed,&vmax);mp[n*2]=0;
    for(int i=1;i<=n;i++)mp[i]=rnd()%vmax+1;
    for(int i=1,op,l,r,x,y;i<=m;i++){
        op=rnd()%4+1;l=rnd()%n+1;r=rnd()%n+1;
        if(l>r)swap(l,r);
        if(op==3)x=rnd()%(r-l+1)+1;
        else x=rnd()%vmax+1;
        if(op==4)y=rnd()%vmax+1;
        split(l);split(r+1);
        if(op==1)for(it=mp.lower_bound(l);it->first<=r;it++)it->second+=x;
        if(op==2){
            for(it=mp.lower_bound(l);it->first<=r;)jt=it++,mp.erase(jt);
            mp[l]=x;
        }
        if(op==3){
            cnt=0;
            for(it=mp.lower_bound(l);it->first<=r;)
                jt=it++,b[++cnt]=mkp(jt->second,it->first-jt->first);
            sort(b+1,b+cnt+1);
            for(int j=1;j<=cnt;j++){
                if(x<=b[j].second){printf("%lld\n",b[j].first);break;}
                x-=b[j].second;
            }
        }
        if(op==4){
            int ans=0;
            for(it=mp.lower_bound(l);it->first<=r;)
                jt=it++,ans=(ans+1ll*power(jt->second%y,x,y)*(it->first-jt->first))%y;
            printf("%d\n",ans);
        }
    }
    return 0;
}