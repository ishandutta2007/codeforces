#include<bits/stdc++.h>
using namespace std;

struct unionfind{
    int n;
    vector<int> fa;

    unionfind(int _n=0){
        fa.resize((n=_n)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[max(x,y)]=min(x,y);
    }
};

int n,d[3005],vis[3005],c[3005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i];
    fill(vis+1,vis+1+n,0);
    unionfind uf(n);
    for(int D=n-1;D;D--)for(int i=1;i<=n;i++)if(d[i]==D&&!vis[i]){
        vis[i]=1;
        for(int j=0;j<d[i];j++){
            cout<<"? "<<i<<endl;
            int u;
            cin>>u;
            uf.unite(i,u);
            if(vis[u])break;
            vis[u]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(uf.find(i)==i){
        c[i]=++cnt;
    }
    cout<<'!';
    for(int i=1;i<=n;i++)cout<<' '<<c[uf.find(i)];
    cout<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}