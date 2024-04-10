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
vector <int> v[200005];
int ans;
int dfs(int x,int from){
    int cnt=0;
    for(auto t:v[x]) if(t!=from) cnt+=dfs(t,x);
    if(!cnt) return 1;
    else{
        ans+=cnt-1;
        return 0;
    }
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        cout<<ans+1<<endl;
    }
    return 0;
}
//
/// 
//01
//