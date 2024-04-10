#include<bits/stdc++.h>
#define ll long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define Mid (L+R>>1)
using namespace std;
const int maxn=1000010,maxm=100010;
const ll inf=1e18;
int i,j,k,n,m;
ll a[maxn],Sum[maxn],tmp[maxn],Mod;
vector<ll>V[maxn*4];
void build(int root,int L,int R){
    if(L!=R){
        // cerr<<"build "<<root<<' '<<L<<' '<<R<<endl;
        build(ls(root),L,Mid);
        build(rs(root),Mid+1,R);
        int p1=0,p2=0,tnum=0;
        for(int i=0;i<=R-L+1;i++)tmp[i]=inf;
        for(;p2<V[rs(root)].size();p2++){
            while(p1+1<V[ls(root)].size() && 
                V[ls(root)][p1+1]+(Sum[Mid]-Sum[L-1])-p1*Mod<=V[rs(root)][p2]){
                    ++p1;
                    tmp[p1+p2-1]=min(tmp[p1+p2-1],
                        max(V[ls(root)][p1],V[rs(root)][p2-1]-(Sum[Mid]-Sum[L-1])+p1*Mod));
                }
            // cerr<<"p1="<<p1<<" p2="<<p2<<' '<<V[ls(root)][p1]<<' '<<V[rs(root)][p2]<<' '<<
            //                     V[rs(root)][p2]-(Sum[Mid]-Sum[L-1])+p1*Mod<<endl;
            tmp[p1+p2]=min(tmp[p1+p2],max(V[ls(root)][p1],V[rs(root)][p2]-(Sum[Mid]-Sum[L-1])+p1*Mod));
        }--p2;
        while(p1+1<V[ls(root)].size())
            ++p1,tmp[p1+p2]=min(tmp[p1+p2],max(V[ls(root)][p1],V[rs(root)][p2]-(Sum[Mid]-Sum[L-1])+p1*Mod));
        for(int i=R-L;i>=0;i--)tmp[i]=min(tmp[i],tmp[i+1]);
        for(int i=0;i<=R-L+1;i++)V[root].push_back(tmp[i]);
    }else V[root].push_back(-inf),V[root].push_back(Mod-a[L]);
}
ll getAns(int root,int L,int R,int l,int r,ll w){
    if(L==l && R==r){
        // cout<<"getAns "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<w<<endl;
        // for(int i=0;i<V[root].size();i++)cout<<V[root][i]<<' ';cout<<endl;
        int g=upper_bound(V[root].begin(),V[root].end(),w)-V[root].begin()-1;
        w+=Sum[R]-Sum[L-1]-g*Mod;
        // cout<<"g="<<g<<' '<<w<<endl;
        return w;
    }else{
        if(r<=Mid)return getAns(ls(root),L,Mid,l,r,w);
        else if(l>Mid)return getAns(rs(root),Mid+1,R,l,r,w);
        else{
            ll t=getAns(ls(root),L,Mid,l,Mid,w);
            // cout<<"t="<<t<<endl;
            return getAns(rs(root),Mid+1,R,Mid+1,r,t);
        }
    }
}
int main(){
    cin>>n>>m>>Mod;
    for(i=1;i<=n;i++)scanf("%lld",&a[i]),Sum[i]=Sum[i-1]+a[i];
    build(1,1,n);
    for(i=1;i<=m;i++){
        int L,R;
        scanf("%d%d",&L,&R);
        ll S=getAns(1,1,n,L,R,0);
        printf("%lld\n",S);
    }
}