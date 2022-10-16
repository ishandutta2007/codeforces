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
const int MAXN=2e5+10;
int T,n,a[MAXN],b[MAXN],indeg[MAXN],cnt[MAXN],arr[MAXN],tot;
queue<int>q;
vector<int>e[MAXN];
int cmp(int x,int y){
    return cnt[x]>cnt[y];
}
void solve(){
    cin>>n;
    rep(i,1,n)indeg[i]=cnt[i]=0,arr[i]=i,e[i].clear();
    rep(i,1,n)cin>>a[i],cnt[a[i]]++;
    rep(i,1,n)cin>>b[i];
    sort(arr+1,arr+1+n,cmp);
    rep(i,1,n){
        if(a[i]==arr[1] || b[i]==arr[1])continue;
        indeg[a[i]]++;
        e[b[i]].push_back(a[i]);
    }
    tot=0;
    rep(i,1,n){
        if(!indeg[i])tot++,q.push(i);
    }
    while(q.size()){
        int u=q.front();q.pop();
        for(auto v:e[u]){
            indeg[v]--;
            if(!indeg[v]){
                q.push(v);tot++;
            }
        }
    }
    if(tot==n)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}