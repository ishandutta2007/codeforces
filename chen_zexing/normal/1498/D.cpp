#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int vis[100005],cnt[100005];
vector <int> v;
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++) vis[i]=-1;
        v.push_back(0);
        vis[0]=0;
        for(int i=1;i<=n;i++) {
            long long t, x, y;
            scanf("%lld%lld%lld", &t, &x, &y);
            for (int j = 0; j < v.size(); j++) cnt[j] = 0;
            for (int j = 0; j < v.size(); j++) {
                int temp = v[j];
                //cout<<j<<" "<<temp<<" "<<vis[v[j]]<<" "<<cnt[j]<<endl;
                if (t == 1) temp = v[j] + ceil(double(x) / 100000);
                else temp = ceil(double(temp) * double(x) / 100000);
                if (temp > m || vis[temp] != -1 || cnt[j] == y) continue;
                v.push_back(temp);
                vis[temp]=i;
                cnt[v.size() - 1] = cnt[j] + 1;
                //cout<<i<<" "<<j<<" "<<temp<<" "<<v[j]<<" "<<vis[temp]<<" "<<cnt[v.size()-1]<<" "<<cnt[j]<<endl;
            }
        }
        for(int i=1;i<=m;i++) printf("%d ",vis[i]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp