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
char s[1005][1005],t[1005];
int a[1005][1005],b[1005];
int l2[105],r2[105],id2[105],l3[1005],r3[1005],id3[1005],pre[1005];
struct ans{
    int l,r,id;
};
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        scanf("%s",t+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j]=s[i][j]-'0';
        for(int i=1;i<=m;i++) b[i]=t[i]-'0';
        memset(l2,0,sizeof(l2)),memset(r2,0,sizeof(r2)),memset(id2,0,sizeof(id2));
        memset(l3,0,sizeof(l3)),memset(r3,0,sizeof(r3)),memset(id3,0,sizeof(id3));
        for(int i=1;i<=n;i++){
            for(int j=2;j<=m;j++){
                int v=a[i][j-1]*10+a[i][j];
                l2[v]=j-1,r2[v]=j,id2[v]=i;
                //cout<<v<<" "<<l2[v]<<" "<<r2[v]<<" "<<id2[v]<<endl;
            }
            for(int j=3;j<=m;j++){
                int v=a[i][j-2]*100+a[i][j-1]*10+a[i][j];
                l3[v]=j-2,r3[v]=j,id3[v]=i;
            }
        }
        memset(pre,-1,sizeof(pre));
        for(int i=2;i<=m;i++){
            int v=b[i-1]*10+b[i];
            if(l2[v]&&(i-2==0||pre[i-2]!=-1)) pre[i]=i-2;
            if(i>=3){
                v=b[i-2]*100+b[i-1]*10+b[i];
                if(l3[v]&&(i-3==0||pre[i-3]!=-1)) pre[i]=i-3;
            }
        }
        if(pre[m]==-1) puts("-1");
        else{
            vector <ans> aa;
            int now=m;
            while(now){
                int v;
                if(pre[now]==now-2) v=b[now-1]*10+b[now],aa.push_back(ans{l2[v],r2[v],id2[v]}),now-=2;
                else v=b[now-2]*100+b[now-1]*10+b[now],aa.push_back(ans{l3[v],r3[v],id3[v]}),now-=3;
            }
            printf("%d\n",aa.size());
            reverse(aa.begin(),aa.end());
            for(auto t:aa) printf("%d %d %d\n",t.l,t.r,t.id);
        }
    }
    return 0;
}