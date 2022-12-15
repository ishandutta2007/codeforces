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
vector <int> v[100005],ans,seq;
int dep[100005],mxdep[100005],fa[100005],rfa[100005],nxt[100005];
bool cmp(int a,int b){
    return mxdep[a]<mxdep[b];
}
void dfs(int x){
    if(!v[x].size()){
        mxdep[x]=dep[x];
        return;
    }
    for(auto t:v[x]) dep[t]=dep[x]+1,dfs(t),mxdep[x]=max(mxdep[x],mxdep[t]);
    sort(v[x].begin(),v[x].end(),cmp);
}
void output(int x){
    seq.push_back(x);
    for(auto t:v[x]) output(t);
}
void solve(int x){
    if(x==0){
        solve(nxt[x]);
        return;
    }
    while(fa[x]!=rfa[x]) fa[x]=fa[fa[x]],ans.push_back(x);
    if(nxt[x]) solve(nxt[x]);
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1,x;i<n;i++) scanf("%d",&x),v[x].push_back(i),rfa[i]=x;
        dfs(0),output(0);
        for(auto x:seq) printf("%d ",x);
        for(int i=0;i<seq.size()-1;i++) fa[seq[i+1]]=seq[i],nxt[seq[i]]=seq[i+1];
        solve(0);
        printf("\n%d\n",ans.size());
        for(auto x:ans) printf("%d ",x);
    }
    return 0;
}
//
/// 
//01
//