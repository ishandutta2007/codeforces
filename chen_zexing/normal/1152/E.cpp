#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[100005],b[100005],d[200005],v[200005];
multiset <int> e[200005];
vector <int> ans;
void dfs(int x){
    while(e[x].size()){
        int nxt=*e[x].begin();
        e[x].erase(e[x].begin()),e[nxt].erase(e[nxt].find(x));
        dfs(nxt);
    }
    ans.push_back(x);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,x=0;
        cin>>n;
        for(int i=1;i<=n-1;i++) scanf("%d",&a[i]),v[++x]=a[i];
        for(int i=1;i<=n-1;i++) scanf("%d",&b[i]),v[++x]=b[i];
        for(int i=1;i<=n-1;i++)
            if(a[i]>b[i]){
                puts("-1");
                exit(0);
            }
        sort(v+1,v+x+1);
        for(int i=1;i<=n-1;i++) a[i]=lower_bound(v+1,v+x+1,a[i])-v;
        for(int i=1;i<=n-1;i++) b[i]=lower_bound(v+1,v+x+1,b[i])-v;
        for(int i=1;i<=n-1;i++) e[a[i]].insert(b[i]),e[b[i]].insert(a[i]),d[a[i]]++,d[b[i]]++;
        int p1=0,p2=0;
        for(int i=1;i<=n*2;i++) if(d[i]%2){
                if(!p1) p1=i;
                else if(!p2) p2=i;
                else{
                    puts("-1");
                    exit(0);
                }
            }
        if(!p1) p1=1;
        dfs(p1);
        if(ans.size()!=n){
            puts("-1");
            continue;
        }
        for(auto t:ans) printf("%d ",v[t]);
    }
    return 0;
}
//
/// 
//01
//