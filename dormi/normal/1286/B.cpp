#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=2e3+1;
vector<int> matrix[MAXN];
int ams[MAXN];
int sts[MAXN];
lli vals[MAXN];
int dfss(int loc, int parent){
   sts[loc]=1;
   for(int x:matrix[loc])if(x!=parent)sts[loc]+=dfss(x,loc);
   return sts[loc];
}
vector<pair<lli,int>> assign(int loc, int parent){
    vector<pair<lli,int>> cur;
    lli largest=0;
    bool done=false;
    for(int x:matrix[loc])if(x!=parent){
        auto te=assign(x,loc);
        lli telargest=0;
        for(auto y:te){
            if(sz(cur)==ams[loc]&&!done){
                cur.push_back({(sz(cur)?cur.back().first:(lli)0)+1,loc});
                largest+=1;
                done=true;
            }
            cur.push_back({y.first+largest,y.second});
            telargest=y.first+largest;
        }
        largest=telargest;
    }
    if(!done){
        cur.push_back({(sz(cur)?cur.back().first:(lli)0)+1,loc});
    }
    return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    int p;
    int root;
    rep(i,1,n+1){
        sc(p,ams[i]);
        if(!p)root=i;
        matrix[p].push_back(i);
        matrix[i].push_back(p);
    }
    dfss(root,0);
    rep(i,1,n+1)if(ams[i]>=sts[i]){
        prl("NO");
        return 0;
    }
    auto te=assign(root,0);
    for(auto x:te){
        vals[x.second]=x.first;
    }
    prl("YES");
    rep(i,1,n+1){
        pr(vals[i],"");
    }
    return 0;
}