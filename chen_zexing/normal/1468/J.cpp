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
struct edge{
    int st,ed,w;
    friend bool operator <(edge a,edge b){
        return a.w<b.w;
    }
};
vector <edge> v;
int fa[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,k;
        cin>>n>>m>>k;
        v.clear();
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            v.push_back(edge{x,y,z});
        }
        sort(v.begin(),v.end());
        long long sum=0;
        for(int i=0;i<v.size();i++){
            int x=v[i].st,y=v[i].ed,w=v[i].w;
            x=find(x),y=find(y);
            if(x==y) continue;
            fa[y]=x;
            if(w>k) sum+=w-k;
        }
        if(sum) printf("%lld\n",sum);
        else{
            int mn=INT_MAX;
            for(int i=0;i<v.size();i++) mn=min(mn,abs(k-v[i].w));
            printf("%d\n",mn);
        }
    }
    return 0;
}