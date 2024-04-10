#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <ctime>

using namespace std;

vector < vector <int> > g;
int in[302],val[302];
vector <int> v;
bool u[302];
int mod=1000000007,t;

void dfs(int i,int sum) {
    u[i]=true;
    v.push_back(sum);
    if (g[i].size()) {
        t-=sum;
        int to=g[i][0];
        if (u[to]||t<0) {
            puts("0");
            exit(0);
        }
        dfs(to,sum+val[to]);
    }
}

int dp[200005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;++i)
        scanf("%d",&val[i]);
    int a,b; g.resize(n);
    for(int i=0;i<m;++i) {
        scanf("%d%d",&a,&b); --a; --b;
        g[a].push_back(b);
        in[b]++;
    }
    v.clear();
    for(int i=0;i<n;++i)
        if (in[i]==0) {
            dfs(i,val[i]);
        }
    for(int i=0;i<n;++i)
        if (!u[i]) {
            puts("0");
            return 0;
        }
    if (t<0) {
        puts("0");
        return 0;
    }
    dp[0]=1;
    for(int i=0;i<v.size();++i)
        for(int j=0;j<=t;++j)
            if (dp[j]&&j+v[i]<=t) {
                dp[j+v[i]]+=dp[j];
                if (dp[j+v[i]]>=mod) dp[j+v[i]]-=mod;
            }
    printf("%d\n",dp[t]);
    return 0;
}