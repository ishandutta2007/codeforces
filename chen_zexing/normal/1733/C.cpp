#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
vector <int> v[2];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        v[0].clear(),v[1].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]%2].push_back(i);
        vector <pair<int,int>> ans;
        int tar=a[1]%2;
        for(int i=int(v[tar].size())-2;i>=0;i--) ans.push_back({v[tar][i],v[tar].back()});
        for(int i=int(v[tar^1].size())-1;i>=0;i--) ans.push_back({1,v[tar^1][i]});
        printf("%d\n",ans.size());
        for(auto t:ans) printf("%d %d\n",t.first,t.second);
    }
    return 0;
}