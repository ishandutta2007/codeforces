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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
vector <int> v[500005],premax[500005],sufmax[500005],premin[500005],sufmin[500005];
int id[500005],pos;
int mx[500005],mn[500005];
bool cmp(int a,int b){
    return premax[a][pos]<premax[b][pos];
}
char ans[500005];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) v[i].resize(m+5),premax[i].resize(m+5),sufmax[i].resize(m+5),premin[i].resize(m+5),sufmin[i].resize(m+5);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&v[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                premax[i][j]=j==1?v[i][j]:max(v[i][j],premax[i][j-1]),premin[i][j]=j==1?v[i][j]:min(v[i][j],premin[i][j-1]);
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                sufmax[i][j]=j==m?v[i][j]:max(v[i][j],sufmax[i][j+1]),sufmin[i][j]=j==m?v[i][j]:min(v[i][j],sufmin[i][j+1]);
        for(int i=1;i<=n;i++) id[i]=i;
        int f=0;
        for(int i=1;i<m&&!f;i++){
            multiset <int> sb,sr;
            pos=i;
            sort(id+1,id+n+1,cmp);
            //for(int j=1;j<=n;j++) cout<<id[j]<<" ";puts("");
            sb.insert(sufmin[id[1]][i+1]);
            for(int j=2;j<=n;j++) sr.insert(sufmax[id[j]][i+1]);
            for(int j=1;j<=n;j++) mx[j]=j==1?premax[id[j]][i]:max(premax[id[j]][i],mx[j-1]);
            for(int j=n;j>=1;j--) mn[j]=j==n?premin[id[j]][i]:min(premin[id[j]][i],mn[j+1]);
            for(int j=1;j<n;j++){
                if(mx[j]<mn[j+1]){
                    auto it=sr.end();
                    --it;
                    if(*sb.begin()>*it){
                        f=1;
                        puts("YES");
                        for(int k=1;k<=n;k++) ans[id[k]]=k<=j?'B':'R';
                        for(int k=1;k<=n;k++) printf("%c",ans[k]);
                        printf(" %d\n",i);
                        break;
                    }
                }
                sb.insert(sufmin[id[j+1]][i+1]);
                sr.erase(sr.find(sufmax[id[j+1]][i+1]));
            }
        }
        if(!f) puts("NO");
    }
    return 0;
}
//
/// 
//01
//