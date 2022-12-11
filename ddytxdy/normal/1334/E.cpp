#include<bits/stdc++.h>
#define LL long long 
#define pli pair<long long,int>
#define pb push_back
#define mp make_pair
using namespace std;
const int mod=998244353,N=100;
LL D,x,y;int q,J[N],I[N];
vector<pli>v;
map<LL,int>mm;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void dfs(int x,int num,int now,LL dat){
    if(x==v.size()){mm[dat]=1ll*now*J[num]%mod;return;}
    LL j=1;
    for(int i=0;i<=v[x].second;i++,j*=v[x].first)
        dfs(x+1,num+i,1ll*now*I[i]%mod,dat*j);
}
int main(){
    scanf("%lld%d",&D,&q);J[0]=I[0]=I[1]=1;
    for(int i=2;i<N;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
    for(int i=1;i<N;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
    for(int i=2;1ll*i*i<=D;i++){
        if(D%i)continue;int num=0;
        while(D%i==0)num++,D/=i;
        v.pb(mp(i,num));
    }
    if(D!=1)v.pb(mp(D,1));
    dfs(0,0,1,1);
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&x,&y);
        LL g=gcd(x,y);x/=g;y/=g;
        printf("%d\n",1ll*mm[x]*mm[y]%mod);
    }
    return 0;
}