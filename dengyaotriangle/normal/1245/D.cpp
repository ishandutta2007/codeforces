#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=2005;

struct edg{
    int u,v;
    long long w;
};

bool operator<(edg a,edg b){
    return a.w<b.w;
}

vector<edg> e;
int n;
long long x[maxn],y[maxn],c[maxn],d[maxn];
int p[maxn];

long long absl(long long x){
    return (x<0?-x:x);
}
int grt(int u){
    if(p[u]==u)return u;
    return p[u]=grt(p[u]);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n+1;i++)p[i]=i;
    for(int i=1;i<=n;i++){
        edg nw;
        nw.u=i;nw.v=n+1;nw.w=c[i];
        e.push_back(nw);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edg nw;
            nw.u=i;nw.v=j;nw.w=(d[i]+d[j])*(absl(x[i]-x[j])+absl(y[i]-y[j]));
            e.push_back(nw);
        }
    }
    sort(e.begin(),e.end());
    long long ans=0;
    vector<int> slf;
    vector<pair<int,int> > cnn;
    for(int i=0;i<e.size();i++){
        edg cur=e[i];
        if(grt(cur.u)!=grt(cur.v)){
            ans+=cur.w;
            p[grt(cur.u)]=grt(cur.v);
            if(cur.v==n+1){
                slf.push_back(cur.u);
            }else{
                cnn.push_back(make_pair(cur.u,cur.v));
            }
        }
    }
    cout<<ans<<'\n'<<slf.size()<<'\n';
    for(int i=0;i<slf.size();i++)cout<<slf[i]<<' ';
    cout<<'\n'<<cnn.size();
    for(int i=0;i<cnn.size();i++)cout<<'\n'<<cnn[i].first<<' '<<cnn[i].second;
    return 0;
}