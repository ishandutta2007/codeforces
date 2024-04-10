#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005];
int fa[200005];
vector<int> s[100005];
vector<pair<int,pair<int,int>>> e;
long long ans;

int find(const int &x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

bool unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return false;
    fa[y]=x;
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=m;i++){
        static int sz;
        cin>>sz;
        s[i].resize(sz);
        for(int &j:s[i]){
            cin>>j;
            e.emplace_back(a[i]+b[j],make_pair(i+n,j));
            ans+=a[i]+b[j];
        }
    }
    sort(e.begin(),e.end());
    reverse(e.begin(),e.end());
    iota(fa,fa+1+n+m,0);
    for(pair<int,pair<int,int>> &p:e){
        const int &u=p.second.first,&v=p.second.second;
        if(unite(u,v)){
            ans-=p.first;
        }
    }
    cout<<ans<<endl;

    return 0;
}