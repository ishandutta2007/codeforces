#include<bits/stdc++.h>
using namespace std;

int n,m,k;
pair<int,int> edge[100005];
int pre[10005][505];
int suf[10005][505];

int find(int *f,int x){
    if(x==f[x])return x;
    else return f[x]=find(f,f[x]);
}

void unite(int *f,int x,int y){
    x=find(f,x);
    y=find(f,y);
    f[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int j=1;j<=n;j++)pre[0][j]=suf[m+1][j]=j;
    for(int i=1;i<=m;i++){
        memcpy(pre[i],pre[i-1],sizeof(pre[i]));
        cin>>edge[i].first>>edge[i].second;
        unite(pre[i],edge[i].first,edge[i].second);
    }
    for(int i=m;i>=1;i--){
        memcpy(suf[i],suf[i+1],sizeof(suf[i]));
        unite(suf[i],edge[i].first,edge[i].second);
    }
    cin>>k;
    while(k--){
        int l,r;
        cin>>l>>r;
        l--;r++;
        int f[505],ans=0;
        bool u[505];
        memset(u,0,sizeof(u));
        memcpy(f,pre[l],sizeof(f));
        for(int i=1;i<=n;i++){
            unite(f,find(suf[r],i),i);
        }
        for(int i=1;i<=n;i++)u[find(f,i)]=1;
        for(int i=1;i<=n;i++)ans+=u[i];
        cout<<ans<<endl;
    }

    return 0;
}