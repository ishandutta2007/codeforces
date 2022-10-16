#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=3e5+10;
struct Node{int fa,sz,w,cnt,d;}dsu[MAXN];
int n,k,num[MAXN][2],ans;
char s[MAXN];
int deb;
int Find(int x){
    if(dsu[x].fa==x)return x;
    int fa=dsu[x].fa;dsu[x].fa=Find(fa);
    dsu[x].w^=dsu[fa].w;
    return dsu[x].fa;
}
int qry(int x){
    x=Find(x);
    if(dsu[x].d==-1)return min(dsu[x].cnt,dsu[x].sz-dsu[x].cnt);
    else if(dsu[x].d==0)return dsu[x].sz-dsu[x].cnt;
    else return dsu[x].cnt;
}
void modify(int x,int val){
    ans-=qry(x);
    int p=Find(x);val^=dsu[x].w;
    dsu[p].d=val;
    ans+=qry(x);
}
void link(int x,int y,int val){
    int p=Find(x),q=Find(y);if(p==q)return;
    ans-=(qry(x)+qry(y));
    val^=dsu[x].w;val^=dsu[y].w;
    if(dsu[p].d==-1 && dsu[q].d>=0)dsu[p].d=dsu[q].d^val;
    if(!val)dsu[p].cnt+=dsu[q].cnt;
    else dsu[p].cnt+=dsu[q].sz-dsu[q].cnt;
    dsu[p].sz+=dsu[q].sz;
    dsu[q].w=val;dsu[q].fa=p;
    ans+=qry(x);
}
void solve(int pos){
    int x=num[pos][0],y=num[pos][1];
    deb=(pos==7);
    if(!y){
        if(s[pos]=='0')modify(x,1);
        else modify(x,0);
    }else{
        if(s[pos]=='0')link(x,y,1);
        else link(x,y,0);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k>>(s+1);
    rep(i,1,k){
        int len,pos;cin>>len;
        while(len--){
            cin>>pos;
            if(!num[pos][0])num[pos][0]=i;
            else num[pos][1]=i;
        }
        dsu[i].fa=i;dsu[i].sz=1;dsu[i].d=-1;dsu[i].cnt=1;
    }
    rep(i,1,n){
        solve(i);
        cout<<ans<<endl;
    }

    return 0;
}