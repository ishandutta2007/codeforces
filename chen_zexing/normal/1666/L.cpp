#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
vector <int> v[200005];
int fa[200005],st[200005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m,s;
        cin>>n>>m>>s;
        for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),v[x].push_back(y);
        queue <int> q;
        for(auto t:v[s]) q.push(t),fa[t]=s,st[t]=t;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto t:v[temp])
                if(st[t]==0&&t!=s){
                    fa[t]=temp,st[t]=st[temp];
                    q.push(t);
                }
        }
        for(int i=1;i<=n;i++) {
            if(st[i]==0) continue;
            for (auto t:v[i])
                if (t != s && st[t] != st[i]) {
                    puts("Possible");
                    vector<int> r1, r2;
                    int now = t;
                    while (now != s) now = fa[now], r1.push_back(now);
                    now = i, r2.push_back(now);
                    while (now != s) now = fa[now], r2.push_back(now);
                    printf("%d\n", r1.size() + 1);
                    for (int k = r1.size() - 1; k >= 0; k--) printf("%d ", r1[k]);
                    printf("%d\n", t);
                    printf("%d\n", r2.size() + 1);
                    for (int k = r2.size() - 1; k >= 0; k--) printf("%d ", r2[k]);
                    printf("%d\n", t);
                    return 0;
                }
        }
        puts("Impossible");
    }
    return 0;
}
//unordered_map