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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
vector <int> v[300005];
int t[300005],nd[300005],k;
void dfs(int x){
    if(v[x].size()==0){
        nd[x]=1,k++;
        return;
    }
    for(int i=0;i<v[x].size();i++) dfs(v[x][i]);
    if(t[x]){
        nd[x]=INT_MAX;
        for(int i=0;i<v[x].size();i++) nd[x]=min(nd[x],nd[v[x][i]]);
    }
    else{
        nd[x]=0;
        for(int i=0;i<v[x].size();i++) nd[x]+=nd[v[x][i]];
    }
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&t[i]);
        for(int i=2,x;i<=n;i++) scanf("%d",&x),v[x].push_back(i);
        dfs(1);
        //for(int i=1;i<=n;i++) cout<<nd[i]<<" ";puts("");
        printf("%d\n",k-nd[1]+1);
    }
    return 0;
}
//
/// 
//01
//