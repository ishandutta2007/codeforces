#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;
int n;
int p[maxn];
int s[maxn];

int fa[maxn],sz[maxn];
int grt(int u){return fa[u]==u?u:fa[u]=grt(fa[u]);}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){cin>>p[i];s[p[i]]=i;}
        for(int i=1;i<=n+1;i++)fa[i]=i,sz[i]=1;
        bool ok=1;
        multiset<int> st;
        for(int i=1;i<=n;i++)st.insert(1);
        for(int i=1;i<=n;i++){
            int pos=s[i];
            auto e=st.end();e--;
            int sze=sz[pos],mx=*e;
            if(sze!=mx){ok=0;break;}
            int rfa=grt(pos+1);
            st.erase(st.find(sze));
            fa[pos]=rfa;
            sz[rfa]+=sz[pos];
            if(rfa<=n)st.insert(sz[rfa]);
        }
        if(ok)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}