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
vector <int> v[1005];
struct edge{
    int x,y;
}e[1005];
int cnt;
void dfs(int x,int from){
    for(auto t:v[x]) if(t!=from) e[++cnt]=edge{x,t},dfs(t,x);
}
int query(vector <int> v){
    printf("? %d ",v.size());
    for(auto t:v) printf("%d ",t);
    puts("");
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        vector <int> temp;
        for(int i=1;i<=n;i++) temp.push_back(i);
        int mx=query(temp);
        int l=1,r=n-1;
        while(l<r){
            int mid=(l+r)>>1;
            set <int> s;
            for(int i=l;i<=mid;i++) s.insert(e[i].x),s.insert(e[i].y);
            temp.clear();
            for(auto it=s.begin();it!=s.end();++it) temp.push_back(*it);
            if(query(temp)==mx) r=mid;
            else l=mid+1;
        }
        printf("! %d %d\n",e[l].x,e[l].y);
    }
    return 0;
}
//
/// 
//01
//