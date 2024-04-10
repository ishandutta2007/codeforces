#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

vector < vector <int> > g;

bool used[1000002];
int timer, tin[1000002], fup[1000002];
set< pair <int,int> > f;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = ++timer;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                if (v<to)
                    f.insert(make_pair(v,to));
                else
                    f.insert(make_pair(to,v));
            }
        }
    }
}

void find(int n) {
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs (i);
}

bool ok(const vector <int> & v,int key) {
    int l=0,r=v.size();
    while(r-l>1) {
        int m=(l+r)>>1;
        if (v[m]>=key) r=m;
        else l=m;
    }
    return r<v.size()&&v[r]==key;
}

long long calc_t(int n) {
    long long ret=0;
    int v,u,top;
    for(int i=0;i<n;++i) {
        for(int j=0;j<g[i].size();++j) {
            v=i; u=g[i][j];
            if (v>u) continue;
            if (f.count(make_pair(v,u))) continue;
            if (g[v].size()>g[u].size()) swap(u,v);
            if (g[u].size()+g[v].size()<200) {
                int l=0,r=0;
                while(l<g[u].size()&&r<g[v].size()) {
                    if (g[u][l]==g[v][r]) ++ret,++l,++r;
                    else {
                        if (g[u][l]<g[v][r]) ++l;
                        else ++r;
                    }
                }
            } else {
                for(int t=0;t<g[v].size();++t) {
                    top=g[v][t];
                    ret+=ok(g[u],top);
    /*              int pos=lower_bound(g[u].begin(),g[u].end(),top)-g[u].begin();
                    if (pos<g[u].size())
                        ret+=g[u][pos]==top;*/
                }
            }
        }
    }
    return ret/3;
}

long long calc_2(int n) {
    long long ret=0;
    for(int i=0;i<n;++i) {
        ret+=1LL*g[i].size()*(g[i].size()-1)/2;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,c;
    scanf("%d%d\n",&n,&m);
    g.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
//  for(int i=0;i<n;++i)
//      sort(g[i].begin(),g[i].end());
//  cout << calc_t(n) << endl;
//  cout << calc_2(n) << endl;
//  find(n);
    long long v3=0,v2=calc_2(n)-3*v3,v1=m;
//  for(int i=0;i<n;++i)
//      if (g[i].size()==1) ++v1;
//  v1/=2;
//  cout << v3 << " " << v2 << "    " << v1 << endl;
    long long bob=1LL*n*(n-1)*(n-2)/6;
    bob+=calc_2(n)-v1*(n-2);
    cout << bob << endl;
    return 0;
}