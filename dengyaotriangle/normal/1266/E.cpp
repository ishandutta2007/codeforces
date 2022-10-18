#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;

int n;
int a[maxn];
long long sum=0,rcnt=0,mor=0;
int b[maxn];
map<pair<int,int>,int> mp;

inline void del(int i,int v,int u){
    rcnt--;
    mor-=max(0,b[u]-a[u]);
    b[u]--;
    mor+=max(0,b[u]-a[u]);
}
inline void add(int i,int v,int u){
    rcnt++;
    mor-=max(0,b[u]-a[u]);
    b[u]++;
    mor+=max(0,b[u]-a[u]);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];sum+=a[i];}
    int q;cin>>q;
    while(q--){
        int i,v,u;
        cin>>i>>v>>u;
        if(mp.find(make_pair(i,v))!=mp.end()){
            del(i,v,mp[make_pair(i,v)]);mp.erase(make_pair(i,v));
        }
        if(u!=0){mp.insert(make_pair(make_pair(i,v),u));
            add(i,v,u);
        }
        cout<<sum-rcnt+mor<<'\n';
    }
    return 0;
}