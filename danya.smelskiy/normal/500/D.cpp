#include <bits/stdc++.h>
using namespace std;


int timer;
int tin[100005];
int cnt[100005];
vector<int> v[100005];
long double ans;
long double n;
int v1[100005];
int v2[100005];
long double z;
long double last[100005];
long double len[100005];

void dfs(int x,int y) {
    cnt[x]=1;
    tin[x]=++timer;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) {
            dfs(to,x);
            cnt[x]+=cnt[to];
        }
    }
}

inline long double get(int xx) {
    int x=v1[xx];
    int y=v2[xx];
    if (tin[x]>tin[y]) swap(x,y);
    long double c1=cnt[1]-cnt[y];
    long double c2=cnt[y];
    long double res=(c1*c2*3ll);
    res*=len[xx];
    res/=z;
    last[xx]=res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    z=(n)*(n-1)/2ll;
    for (int i=1;i<n;++i) {
        cin>>v1[i]>>v2[i]>>len[i];
        v[v1[i]].push_back(v2[i]);
        v[v2[i]].push_back(v1[i]);
    }
    dfs(1,-1);
    for (int i=1;i<n;++i) {
        ans+=get(i);
    }
    int m;
    cout<<fixed<<setprecision(6);
    cin>>m;
    while (m--) {
        int x,y;
        cin>>x>>y;
        ans-=last[x];
        len[x]=y;
        ans+=get(x);
        cout<<ans<<'\n';
    }
}