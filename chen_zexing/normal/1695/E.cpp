#pragma GCC optimize(3)
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
#include <bitset>
using namespace std;
multiset <int> v[600005];
vector <int> a;
vector <pair<int,int>> ans;
vector <string> s1,s2;
int vis[600005];
void dfs(int x){
    if(vis[x]){
        a.push_back(x);
        return;
    }
    vis[x]=1;
    a.push_back(x);
    while(v[x].size()){
        int tar=*v[x].begin();
        v[tar].erase(v[tar].find(x));
        v[x].erase(v[x].begin());
        dfs(tar);
        a.push_back(x);
    }
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),v[x].insert(y),v[y].insert(x);
        for(int i=1;i<=n*2;i++)
            if(!vis[i]&&v[i].size()) {
                a.clear();
                dfs(i);
                a.pop_back();
                if(a.size()==2){
                    puts("-1");
                    return 0;
                }
                for(int j=0;j<a.size()/2;j++) ans.push_back(make_pair(a[j],a[a.size()-j-1]));
                int cnt=a.size()/2;
                if(cnt%2){
                    for(int j=1;j<=(cnt-1)/2;j++) s1.push_back("UU"),s1.push_back("DD");
                    s1.push_back("LR");
                    s2.push_back("LR");
                    for(int j=1;j<=(cnt-1)/2;j++) s2.push_back("UU"),s2.push_back("DD");
                }
                else{
                    for(int j=1;j<=cnt/2;j++) s1.push_back("UU"),s1.push_back("DD");
                    s2.push_back("LR");
                    for(int j=1;j<=cnt/2-1;j++) s2.push_back("UU"),s2.push_back("DD");
                    s2.push_back("LR");
                }
            }
        printf("%d 2\n",n);
        for(auto t:ans) printf("%d %d\n",t.first,t.second);
        for(auto t:s1) printf("%c%c\n",t[0],t[1]);
        for(auto t:s2) printf("%c%c\n",t[0],t[1]);
    }
    return 0;
}
//cf