#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[500005];
int t[500005];
int v[500005];
bool u[500005];
int ans[500005];

int main(){

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",t+i);
    }
    iota(v+1,v+1+n,1);
    sort(v+1,v+1+n,[](const int &a,const int &b){
        return t[a]<t[b];
    });
    for(int i=1;i<=n;i++){
        int &x=v[i];
        u[x]=1;
        set<int> s;
        for(int &y:g[x]){
            if(u[y])s.insert(t[y]);
        }
        if(s.size()!=t[x]-1||(!s.empty()&&*s.rbegin()>=t[x])){
            puts("-1");
            return 0;
        }
        ans[i]=x;
    }
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);

    return 0;
}