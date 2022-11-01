#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,a,b;
int h[1005][1005];
int minHor[1005][1005];
int minGrid[1005][1005];
ll preSum[1005][1005];
pair<ll,pair<int,int> > minCost[1000005];
int minCostCnt;
bool u[1005][1005];
pair<pair<int,int>,ll> v[1000005];
int vCnt;
int deq[1005];
int s,t;

inline ll sum(int x,int y){
    return preSum[x+a-1][y+b-1]-preSum[x-1][y+b-1]-preSum[x+a-1][y-1]+preSum[x-1][y-1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d %d %d",&n,&m,&a,&b);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&h[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        s=t=0;
        int cur=1;
        for(int j=1;j+b-1<=m;j++){
            while(cur<=j+b-1){
                while(s<t&&h[i][deq[t-1]]>=h[i][cur])t--;
                deq[t++]=cur;
                cur++;
            }
            minHor[i][j]=h[i][deq[s]];
            if(deq[s]==j){
                s++;
            }
        }
    }
    for(int j=1;j+b-1<=m;j++){
        s=t=0;
        int cur=1;
        for(int i=1;i+a-1<=n;i++){
            while(cur<=i+a-1){
                while(s<t&&minHor[deq[t-1]][j]>=minHor[cur][j])t--;
                deq[t++]=cur;
                cur++;
            }
            minGrid[i][j]=minHor[deq[s]][j];
            if(deq[s]==i){
                s++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+h[i][j];
        }
    }
    for(int i=1;i+a-1<=n;i++){
        for(int j=1;j+b-1<=m;j++){
            minCost[minCostCnt++]=make_pair(sum(i,j)-(ll(minGrid[i][j]))*a*b,make_pair(i,j));
        }
    }
    sort(minCost,minCost+minCostCnt);
    for(int i=0;i<minCostCnt;i++){
        ll cost=minCost[i].first;
        int x=minCost[i].second.first;
        int y=minCost[i].second.second;
        if(!u[x][y]&&!u[x+a-1][y+b-1]&&!u[x+a-1][y]&&!u[x][y+b-1]){
            for(int i=x;i<x+a;i++){
                for(int j=y;j<y+b;j++){
                    u[i][j]=true;
                }
            }
            v[vCnt++]=make_pair(make_pair(x,y),cost);
        }
    }
    printf("%d\n",vCnt);
    for(int i=0;i<vCnt;i++){
        printf("%d %d %I64d\n",v[i].first.first,v[i].first.second,v[i].second);
    }

    return 0;
}