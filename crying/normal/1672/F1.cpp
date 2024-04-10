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
int T,n,a[MAXN],b[MAXN],arr[MAXN];
vector<int>cyc[MAXN],occ[MAXN];
int cmp(int x,int y){
    return occ[x].size()>occ[y].size();
}
void solve(){
    cin>>n;
    rep(i,1,n)arr[i]=i,cyc[i].clear(),occ[i].clear();
    rep(i,1,n)cin>>a[i],occ[a[i]].push_back(i);
    sort(arr+1,arr+1+n,cmp);
    rep(i,1,n){
        int val=arr[i];
        rep(j,1,occ[val].size()){
            cyc[j].push_back(occ[val][j-1]);
        }
    }
    rep(i,1,n){
        int sz=cyc[i].size();
        rep(j,0,sz-1){
            b[cyc[i][(j+1)%sz]]=a[cyc[i][j]];
        }
    }
    rep(i,1,n)cout<<b[i]<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}