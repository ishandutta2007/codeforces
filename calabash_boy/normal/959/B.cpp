#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
string a[maxn];
int cost[maxn];
int fa[maxn];
int ans[maxn];
map<string,int>id;
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        id[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        cin>>cost[i];
        fa[i]=i;
        ans[i] = 1e9+100;
    }
    for (int i=0;i<k;i++){
        int x;
        cin>>x;
        int u;
        cin>>u;
        x--;
        while (x--){
            int v;
            cin>>v;
            int fu = find(u);
            int fv = find(v);
            if (fu!=fv){
                fa[fu] = fv;
            }
            u = v;
        }
    }
    for (int i=1;i<=n;i++){
        ans[find(i)] = min(ans[find(i)],cost[i]);
    }
    long long anss =0;
    for (int i=0;i<m;i++){
        string temp;
        cin>>temp;
        anss+=ans[find(id[temp])];
    }
    cout<<anss<<endl;
    return 0;
}