#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

int dist[62][62][62];
int dp[62][62][65];
int mn[62][62];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int t=0;t<m;++t) {
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",&dist[t][i][j]);
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if (i!=j&&i!=k&&j!=k)
                        dist[t][i][j]=min(dist[t][i][j],dist[t][i][k]+dist[t][k][j]);
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) {
            mn[i][j]=0;
            for(int t=0;t<m;++t)
                if (dist[t][i][j]<dist[mn[i][j]][i][j])
                    mn[i][j]=t;
        }
    int INF=1000000000;
    for(int start=0;start<n;++start)
        for(int cur=0;cur<n;++cur)
                for(int dif=0;dif<=61;++dif)
                    dp[start][cur][dif]=INF;
    for(int i=0;i<n;++i)
            dp[i][i][0]=0;
    vector < pair <pair<int,int>, pair <int,int> > > q;
    for(int dif=0;dif<=61;++dif) {
        for(int start=0;start<n;++start)
            for(int cur=0;cur<n;++cur)
                    q.push_back(make_pair(make_pair(dp[start][cur][dif],start),make_pair(cur,0)));
        sort(q.begin(),q.end());
        for(int i=0;i<q.size();++i) {
            int start=q[i].first.second,cur=q[i].second.first;
            if (dp[start][cur][dif]!=-1) {
                for(int next=0;next<n;++next) {
                    dp[start][next][dif+1]=min(dp[start][next][dif+1],dp[start][cur][dif]+dist[mn[cur][next]][cur][next]);
                }
            }
        }
        q.clear();
    }
    for(int start=0;start<n;++start)
        for(int cur=0;cur<n;++cur)
                for(int dif=1;dif<=61;++dif)
                    dp[start][cur][dif]=min(dp[start][cur][dif],dp[start][cur][dif-1]);
    for(int t=0;t<r;++t) {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        --a; --b;
        if (k>60) k=60;
        int ans=dp[a][b][k+1];
        printf("%d\n",ans);
    }
    return 0;
}