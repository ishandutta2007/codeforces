#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>

using namespace std;

int arr[102],x[102],y[102];

bool ok(int n,int d,int am) {
    priority_queue < pair <long long,int> > q;
    q.push(make_pair(am,0));
    vector <long long> dist(n,-1); dist[0]=am;
    while(!q.empty()) {
        pair <int,int> top=q.top(); q.pop();
        if (dist[top.second]!=top.first) continue;
        for(int i=0;i<n;++i) {
            if (i==top.second) continue;
            long long ndist=top.first+arr[i]-d*(abs(x[top.second]-x[i])+abs(y[top.second]-y[i]));
            if (ndist>dist[i]) {
                dist[i]=ndist;
                q.push(make_pair(ndist,i));
            }
        }
    }
    return dist[n-1]>=0;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<n-1;++i)
        scanf("%d",&arr[i]);
    for(int i=0;i<n;++i)
        scanf("%d%d",&x[i],&y[i]);
    int l=-1,r=20000*d;
    while(r-l>1) {
        int m=(l+r)>>1;
        if (ok(n,d,m)) r=m;
        else l=m;
    }
    printf("%d\n",r);
    return 0;
}