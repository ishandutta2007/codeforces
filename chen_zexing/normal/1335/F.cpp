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
string s[1000005],f[1000005];
int in[1000005];
vector <int> inn[1000005];
int out[1000005],fa[1000005],c[1000005],fl[1000005],can[1000005],vis[1000005],sz[1000005],con[1000005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int step){
    if(vis[x]>0){
        return;
    }
    vis[x]=step;
    can[step]|=fl[x];
    for(int i=0;i<inn[x].size();i++) dfs(inn[x][i],step+1);
}
int main() {
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n*m;i++) fa[i]=i,c[i]=1,in[i]=0,vis[i]=-1,sz[i]=1,inn[i].clear();
        for(int i=0;i<n;i++) cin>>f[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                fl[i*m+j]=(f[i][j]-'0')^1;
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int st=i*m+j,ed;
                if(s[i][j]=='U') ed=(i-1)*m+j;
                else if(s[i][j]=='D') ed=(i+1)*m+j;
                else if(s[i][j]=='L') ed=st-1;
                else ed=st+1;
                inn[ed].push_back(st);
                in[ed]++;
                out[st]=ed;
                if(find(st)!=find(ed)) {
                    sz[find(ed)]+=sz[find(st)];
                    fa[find(st)] = find(ed);
                }
            }
        queue <int> q;
        for(int i=0;i<n*m;i++)
            if(in[i]==0)
                q.push(i),c[i]=0;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            in[out[t]]--;
            if(in[out[t]]==0) q.push(out[t]),c[out[t]]=0;
        }
        int ans1=0,ans2=0;
        for(int i=0;i<n*m;i++){
            if(c[i]) ans1++;
        }
        for(int i=0;i<n*m;i++){
            if(c[i]){
                if(vis[i]!=-1) continue;
                int temp=find(i);
                //cout<<temp<<" "<<sz[temp]<<endl;
                for(int j=0;j<=sz[temp];j++) can[j]=0,con[j]=0;
                dfs(i,0);
                int len=vis[i];
                //cout<<len<<endl;
                for(int j=0;j<=sz[temp];j++)
                    if(can[j]&&con[j%len]==0)
                        ans2++,con[j%len]=1;
                //cout<<ans2<<endl;
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}