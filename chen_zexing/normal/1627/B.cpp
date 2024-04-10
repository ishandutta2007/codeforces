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
using namespace std;
vector <int> d[100005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int cnt[200005];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) d[i].clear(),d[i].resize(m+5);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                d[i][j]=-1;
        for(int i=1;i<=n+m;i++) cnt[i]=0;
        queue <pair<int,int>> q;
        for(int i=(n+1)/2;i<=(n+2)/2;i++)
            for(int j=(m+1)/2;j<=(m+2)/2;j++)
                d[i][j]=0,q.push(make_pair(i,j)),cnt[0]++;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int xx=temp.first+dx[i],yy=temp.second+dy[i];
                if(xx>n||yy>m||xx==0||yy==0) continue;
                if(d[xx][yy]==-1) d[xx][yy]=d[temp.first][temp.second]+1,q.push(make_pair(xx,yy)),cnt[d[xx][yy]]++;
            }
        }
        int now=0,v=n/2+m/2;
        //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
        for(int i=1;i<=n*m;i++){
            if(cnt[now]==0) now++;
            cnt[now]--;
            printf("%d ",v+now);
        }
        puts("");
    }
    return 0;
}