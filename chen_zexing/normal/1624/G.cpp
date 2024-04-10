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
struct edge{
    int ed,w;
    friend bool operator <(edge a,edge b){
        return a.ed<b.ed||a.ed==b.ed&&a.w<b.w;
    }
};
vector <edge> s[200005];
int fa[200005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) s[i].clear();
        for(int i=1,x,y,w;i<=m;i++){
            scanf("%d%d%d",&x,&y,&w);
            s[x].push_back(edge{y,w}),s[y].push_back(edge{x,w});
        }
        for(int i=30;i>=0;i--){
            for(int j=1;j<=n;j++) fa[j]=j;
            int cnt=n;
            for(int j=1;j<=n;j++)
                for(auto t:s[j])
                    if(((1<<i)&t.w)==0){
                        int x=find(j),y=find(t.ed);
                        if(x!=y) fa[y]=x,cnt--;
                    }
            if(cnt==1) {
                for (int j = 1; j <= n; j++) {
                    vector <edge> temp;
                    for (auto t:s[j])
                        if (((1 << i) & t.w)==0)
                            temp.push_back(t);
                    s[j]=temp;
                }
            }
            else ans+=1<<i;
        }
        cout<<ans<<endl;
    }
    return 0;
}