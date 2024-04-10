#include<bits/stdc++.h>
using namespace std;
vector<array<int,3>> v[30010];
stack<int> ans;
int c[30010]={};
priority_queue<array<int,2>> q;
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < 4*n; ++i) {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        v[a].push_back({b,c,i+1});
    }
    for(int i = 0; i < n; ++i) q.push({0,i+1});
    while(q.size()) {
        auto t = q.top(); q.pop();
        int x = t[1];
        if(t[0] != c[x] || v[x].size()==0) continue;
        auto a = v[x].back(); v[x].pop_back();
        c[x]--;c[a[0]]++;c[a[1]]++;ans.push(a[2]);
        q.push({c[x],x}); q.push({c[a[0]],a[0]}); q.push({c[a[1]],a[1]});
    }
    puts("YES"); while(ans.size()) {printf("%d ", ans.top()); ans.pop();} puts("");
    return 0;
}