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
char s[205];
int f[26][26],vis[26];
vector <int> v[26];
vector <int> c[3];
vector <int> ans;
int fl=1;
void dfs(int x,int from){
    if(vis[x]){
        fl=0;
        return;
    }
    ans.push_back(x);
    vis[x]=1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from)
            dfs(v[x][i],x);
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%s",s+1);
        int l=strlen(s+1);
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<26;i++) v[i].clear();
        for(int i=0;i<3;i++) c[i].clear();
        ans.clear();
        for(int i=1;i<l;i++){
            int x=s[i]-'a',y=s[i+1]-'a';
            if(f[x][y]) continue;
            v[x].push_back(y);
            v[y].push_back(x);
            f[x][y]=f[y][x]=1;
        }
        fl=1;
        for(int i=0;i<26;i++) if(v[i].size()>=3) fl=0;
        for(int i=0;i<26;i++){
            if(!vis[i]&&v[i].size()==1){
                dfs(i,26);
            }
        }
        //cout<<'#'<<fl;
        for(int i=0;i<26;i++) if(v[i].size()==2&&!vis[i]) fl=0;
        if(!fl) puts("NO");
        else{
            puts("YES");
            for(int i=0;i<26;i++) if(v[i].size()==0) ans.push_back(i);
            for(int i=0;i<26;i++) printf("%c",ans[i]+'a');
            puts("");
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp