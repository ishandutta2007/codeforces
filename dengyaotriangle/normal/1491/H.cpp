#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int blk=256;
const int maxn=100005+blk*2;

int n,q;
int top[maxn],fa[maxn],dlt[maxn];
bool typ[maxn];

int gtop(int x){
    if(x==0)return -1;
    int r=x/blk;
    if(typ[r])return max(0,fa[x]-dlt[r]);
    return top[x];
}
int gfa(int x){
    if(x==0)return -1;
    int r=x/blk;
    if(typ[r])return max(0,fa[x]-dlt[r]);
    return fa[x];
}
void upd(int id){
    if(typ[id])return;
    int l=id*blk,r=id*blk+blk;
    for(int i=l;i<r;i++)fa[i]=max(0,fa[i]-dlt[id]);
    dlt[id]=0;
    typ[id]=1;
    for(int i=l;i<r;i++){
        if(fa[i]<l)top[i]=fa[i];
        else top[i]=top[fa[i]],typ[id]=0;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    fa[0]=0;
    for(int i=1;i<n;i++)cin>>fa[i],fa[i]--;
    for(int i=0;i*blk<n;i++)upd(i);
    while(q--){
        int op,x,y;
        cin>>op>>x>>y;x--;y--;
        if(op==1){
            int md;cin>>md;
            int rl=x/blk,rr=y/blk;
            if(rl==rr){
                for(int i=x;i<=y;i++)fa[i]-=md;
                upd(rl);
            }else{
                for(int i=rl+1;i<rr;i++){
                    dlt[i]+=md;
                    upd(i);
                }
                for(int i=x;i<(rl+1)*blk;i++)fa[i]-=md;
                upd(rl);
                for(int i=rr*blk;i<=y;i++)fa[i]-=md;
                upd(rr);
            }
        }else{
            while(gtop(x)!=gtop(y)){
                if(gtop(x)<gtop(y))swap(x,y);
                x=gtop(x);
            }
            while(x!=y){
                if(gfa(x)<gfa(y))swap(x,y);
                x=gfa(x);
            }
            cout<<x+1<<'\n';
        }
    }
    return 0;
}