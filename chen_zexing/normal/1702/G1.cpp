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
#include <assert.h>
#include <random>
using namespace std;
vector <int> v[200005];
int fa[200005][20],dep[200005];
void dfs(int x,int from){
    fa[x][0]=from,dep[x]=dep[from]+1;
    for(auto t:v[x])
        if(t!=from)
            dfs(t,x);
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    //cout<<x<<" "<<y<<" ";
    for(int i=19;i>=0;i--)
        if(dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    //cout<<x<<" "<<y<<" "<<fa[x][0]<<endl;
    return fa[x][0];
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y),v[y].push_back(x);
        }
        dfs(1,0);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                fa[j][i]=fa[fa[j][i-1]][i-1];
        int q;
        scanf("%d",&q);
        for(int i=1,k;i<=q;i++){
            scanf("%d",&k);
            int fl=1,e1,e2,l;
            for(int j=1,x;j<=k;j++){
                scanf("%d",&x);
                if(!fl) continue;
                if(j==1) e1=e2=l=x;
                else{
                    if(l==e2) swap(e1,e2);
                    if(l==e1){
                        int l1=lca(e1,x),l2=lca(e2,x);
                        if(l1==x&&l2==x) e1=x;
                        else if(l1!=l&&l1==l2) e1=x;
                        else if(l1==l&&l2==x);
                        else if(l1==l&&l2==e2) e2=x;
                        else if(l1==l&&l2==l) e1=x;
                        else{
                            fl=0;
                            continue;
                        }
                        l=lca(e1,e2);
                    }
                    else{
                        int l1=lca(e1,x),l2=lca(e2,x),ll=lca(l,x);
                        if(ll!=l){
                            fl=0;
                            continue;
                        }
                        if(l1==e1) e1=x;
                        else if(l1==x&&l2==l);
                        else if(l2==x&&l1==l);
                        else if(l2==e2) e2=x;
                        else{
                            fl=0;
                            continue;
                        }
                        l=lca(e1,e2);
                    }
                }
                //cout<<e1<<" "<<e2<<" "<<l<<endl;
            }
            puts(fl?"YES":"NO");
        }
    }
    return 0;
}
//unordered_map