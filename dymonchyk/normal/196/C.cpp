#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>

using namespace std;

vector < vector <int> > g;
int n;

struct Point{
    Point(int _x = 0,int _y = 0,int _index = 0) : x(_x), y(_y), index(_index) {};
    int x,y,index;
};

bool operator < (const Point & a,const Point & b) {
    if (a.x==0&&a.y==0) return true;
    return 1LL*a.x*b.y<1LL*b.x*a.y;
}

vector <Point> v;
int ans[1502];
int size[1502];

int dfs2(int cur = 0,int par = -1) {
    int cnt=1;
    for(int i=0;i<g[cur].size();++i)
        if (g[cur][i]!=par) cnt+=dfs2(g[cur][i],cur);
    return size[cur]=cnt;
}

void dfs(int cur,int par,vector <Point> v) {
    int ind=0;
    for(int i=0;i<v.size();++i)
        if (v[i].x<v[ind].x||v[i].x==v[ind].x&&v[i].y<v[ind].y) ind=i;
    for(int i=0;i<v.size();++i)
        if (i!=ind) v[i].x-=v[ind].x,v[i].y-=v[ind].y;
    v[ind].x=v[ind].y=0;
    sort(v.begin(),v.end());

    ans[v[0].index]=cur+1;
    v.erase(v.begin());
    int last=0;
    for(int i=0;i<g[cur].size();++i) {
        if (g[cur][i]!=par) {
            dfs(g[cur][i],cur,vector <Point>(v.begin()+last,v.begin()+last+size[g[cur][i]]));
            last+=size[g[cur][i]];
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b;
    scanf("%d",&n);
    g.resize(n);
    for(int i=0;i<n-1;++i) {
        scanf("%d%d",&a,&b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;++i) {
        scanf("%d%d",&a,&b);
        v.push_back(Point(a,b,i));
    }
    dfs2(); dfs(0,-1,v);
    printf("%d",ans[0]);
    for(int i=1;i<n;++i)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}