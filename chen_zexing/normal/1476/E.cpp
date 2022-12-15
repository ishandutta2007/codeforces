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
map <string,int> mp;
string p[100005],s[100005];
int mt[100005];
vector <int> v[100005],out[100005],ans;
int in[100005],f[100005];
queue <int> q;
int main() {
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) cin>>p[i],mp[p[i]]=i;
        int fl=1;
        for(int i=1;i<=m;i++){
            cin>>s[i];
            scanf("%d",&mt[i]);
            for(int j=0;j<(1<<k);j++){
                string temp="";
                for(int t=0;t<k;t++) temp+=((j&(1<<t))?s[i][t]:'_');
                if(mp[temp]) v[i].push_back(mp[temp]);
            }
            int pos=-1;
            for(int j=0;j<v[i].size();j++)
                if(v[i][j]==mt[i])
                    pos=j;
            if(pos==-1){
                fl=0;
                break;
            }
            for(int j=0;j<v[i].size();j++)
                if(v[i][j]!=mt[i])
                    out[mt[i]].push_back(v[i][j]),in[v[i][j]]++;
        }
        for(int i=1;i<=n;i++)
            if(in[i]==0)
                q.push(i),f[i]=1,ans.push_back(i);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i=0;i<out[t].size();i++)
            {
                in[out[t][i]]--;
                if(in[out[t][i]]==0){
                    f[out[t][i]]=1;
                    q.push(out[t][i]);
                    ans.push_back(out[t][i]);
                }
            }
        }
        for(int i=1;i<=n;i++)
            if(!f[i])
                fl=0;
        if(fl){
            puts("YES");
            for(int i=0;i<n;i++) printf("%d ",ans[i]);
        }
        else puts("NO");
    }
    return 0;
}