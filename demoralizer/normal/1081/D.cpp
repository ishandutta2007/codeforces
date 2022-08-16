#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
map<int,int> v[100005];
int x[100005],vis[100005],d[100005];
set<pii> s;set<int> uu;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int t;cin>>t;
        x[i]=t;
        uu.insert(t);
    }
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        if(a==b)continue;
        if(v[a][b]==0||w<v[a][b]){
            v[a][b]=w;
            v[b][a]=w;
        }
    }
    int t=x[0];
    d[t]=0;
    s.insert({0,x[0]});
    set<pii>::iterator it;
    while(!s.empty()){
        it=s.begin();
        int a=(*it).fr,b=(*it).sc;
        s.erase(it);
        if(vis[b]){continue;}
        vis[b]=1;d[b]=a;
        for(mii::iterator i=v[b].begin();i!=v[b].end();i++){
            if(vis[i->fr])continue;
            s.insert({max(i->sc,a),i->fr});
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
    		if(uu.find(i)==uu.end()) continue;
        if(d[i]>ans)ans=d[i];
    }
    for(int i=0;i<k;i++){
        cout<<ans<<" ";
    }
}