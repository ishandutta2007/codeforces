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
vector <int> v[200005],inv[200005];
int in[200005],ans[200005];
struct node{
    int x,d;
    friend bool operator <(node a,node b){
        return a.d>b.d;
    }
};
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y),inv[y].push_back(x),in[x]++;
        }
        priority_queue <node> q;
        q.push(node{n,0});
        memset(ans,-1,sizeof(ans));
        while(!q.empty()){
            auto temp=q.top();
            q.pop();
            if(ans[temp.x]!=-1) continue;
            ans[temp.x]=temp.d;
            for(auto x:inv[temp.x]){
                in[x]--;
                q.push(node{x,in[x]+temp.d+1});
            }
        }
        printf("%d\n",ans[1]);
    }
    return 0;
}