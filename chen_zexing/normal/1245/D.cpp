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
#define hash hassh
using namespace std;
long long cost[2005][2005],dis[2005];
struct city{
    long long x,y,c,k;
}a[2005];
struct edge{
    int st,ed;
};
int f[2005],from[2005];
vector <int> st;
vector <edge> e;
long long ans=0;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].c);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i].k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cost[i][j]=(a[i].k+a[j].k)*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
    for(int i=1;i<=n;i++) cost[i][0]=cost[0][i]=a[i].c,dis[i]=LLONG_MAX;
    dis[0]=0;
    for(int i=1;i<=n;i++){
        dis[i]=min(dis[i],cost[0][i]);
        from[i]=0;
    }
    for(int i=1;i<=n;i++){
        int p=0;
        long long mn=LLONG_MAX;
        for(int j=1;j<=n;j++)
            if(!f[j]&&mn>dis[j]) {
                mn = dis[j];
                p = j;
            }
        if(from[p]==0){
            st.push_back(p);
        }
        else{
            e.push_back(edge{from[p],p});
        }
        ans+=mn;
        f[p]=1;
        for(int j=1;j<=n;j++){
            dis[j]=min(dis[j],cost[p][j]);
            if(dis[j]==cost[p][j]){
                from[j]=p;
            }
        }
        //cout<<ans<<" "<<p<<" "<<mn<<endl;
    }
    printf("%lld\n",ans);
    printf("%d\n",st.size());
    for(int i=0;i<st.size();i++) printf("%d ",st[i]);
    printf("\n%d\n",e.size());
    for(int i=0;i<e.size();i++) printf("%d %d\n",e[i].st,e[i].ed);
    return 0;
}