#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=105,C=40;

int n,dp[maxn][maxn];
pii to[maxn][maxn];
bool vis[maxn][maxn];

int solve(int x, int y){
    if(x<=2) return 0;
    if(vis[x][y]) return dp[x][y];
    //bug(x,y);
    dp[x][y]=inf;
    rep(i,0,y+1) rep(j,0,x-y+1){
        int good=0;
        if(pii(y+j,i+j)<pii(x,y)) good++;
        if(pii(x-j,x-i-j)<pii(x,y)) good++;
        if(good<2) continue;
        dp[x][y]=min(dp[x][y],max(solve(y+j,i+j),solve(x-j,x-i-j))+1);
    }
    rep(i,0,y+1) rep(j,0,x-y+1){
        int good=0;
        if(pii(y+j,i+j)<pii(x,y)) good++;
        if(pii(x-j,x-i-j)<pii(x,y)) good++;
        if(good<2) continue;
        if(max(solve(y+j,i+j),solve(x-j,x-i-j))+1==dp[x][y]) to[x][y]={i,j};
    }
    vis[x][y]=1;
    return dp[x][y];
}

void solve(vector<int> vec1, vector<int> vec2){
    if(sz(vec1)+sz(vec2)<=2){
        for(auto i: vec2) vec1.pb(i);
        for(auto i: vec1){
            cout << "! " << i << endl;
            string str;
            cin >> str;
            if(str.back()==')') exit(0);
        }
        assert(false);
    }
    pii p;
    if(sz(vec1)+sz(vec2)<100) p=to[sz(vec1)+sz(vec2)][sz(vec1)];
    else p={sz(vec1)/2,sz(vec2)/2};
    cout << "? " << p.first+p.second << ' ';
    rep(i,0,p.first) cout << vec1[i] << ' ';
    rep(i,0,p.second) cout << vec2[i] << ' ';
    cout << endl;
    string str;
    cin >> str;
    vector<int> vec3,vec4;
    if(str[0]=='Y'){
        rep(i,0,p.first) vec3.pb(vec1[i]);
        rep(i,0,p.second) vec3.pb(vec2[i]);
        rep(i,p.first,sz(vec1)) vec4.pb(vec1[i]);
    }
    else{
        rep(i,p.first,sz(vec1)) vec3.pb(vec1[i]);
        rep(i,p.second,sz(vec2)) vec3.pb(vec2[i]);
        rep(i,0,p.first) vec4.pb(vec1[i]);
    }
    solve(vec3,vec4);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(i,2,100) rep(j,0,i+1) solve(i,j);
    int n;
    cin >> n;
    vector<int> vec;
    rep(i,1,n+1) vec.pb(i);
    solve(vec,{});
}