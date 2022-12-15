#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[2005][2005];
struct pos{
    int x,y;
};
struct answer{
    int x1,y1,x2,y2;
}ans[26];
vector <pos> v[26];
int check_r(int id){
    for(int i=0;i<v[id].size();i++)
        if(v[id][i].x!=v[id][0].x)
            return 0;
    return 1;
}
int check_c(int id){
    for(int i=0;i<v[id].size();i++)
        if(v[id][i].y!=v[id][0].y)
            return 0;
    return 1;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,mx=-1;
        cin>>n>>m;
        for(int i=0;i<26;i++) v[i].clear();
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]>='a'&&s[i][j]<='z'){
                    v[s[i][j]-'a'].push_back(pos{i,j});
                    mx=max(mx,int(s[i][j]-'a'));
                }
        if(mx==-1){
            puts("YES");
            puts("0");
            continue;
        }
        int f=1;
        for(int i=mx;i>=0;i--){
            if(v[i].size()==0){
                ans[i]=ans[mx];
            }
            else if(check_r(i)){
                int l=INT_MAX,r=0,x;
                for(int j=0;j<v[i].size();j++) l=min(l,v[i][j].y),r=max(r,v[i][j].y),x=v[i][j].x;
                for(int j=l;j<=r;j++) if(s[x][j]=='.'||s[x][j]-'a'<i) f=0;
                if(f) ans[i]=answer{x,l,x,r};
            }
            else if(check_c(i)){
                int l=INT_MAX,r=0,x;
                for(int j=0;j<v[i].size();j++) l=min(l,v[i][j].x),r=max(r,v[i][j].x),x=v[i][j].y;
                for(int j=l;j<=r;j++) if(s[j][x]=='.'||s[j][x]-'a'<i) f=0;
                if(f) ans[i]=answer{l,x,r,x};
            }
            else f=0;
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            printf("%d\n",mx+1);
            for(int i=0;i<=mx;i++) printf("%d %d %d %d\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2);
        }
    }
    return 0;
}
//
/// 
//01
//