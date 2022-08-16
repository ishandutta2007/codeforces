#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

int cost[100005],vis[100005],ini[100005],lb[100005];
int abmc=0,abtw=1;
vc<int> v[100005];

piii dfs(int z,int iniz,int lev){
    if(vis[z]){
        if(ini[z]!=iniz)return {-1,{-1,1}};
        return {lb[z],{-1,1}};
    }
    vis[z]=1;
    lb[z]=lev;
    ini[z]=iniz;
    int cmi=-1,mc=-1,tw=1;
    for(int k:v[z]){
        piii t=dfs(k,iniz,lev+1);if(t.fr==-1)continue;
        if(cmi==-1||t.fr<cmi)cmi=t.fr;if(t.sc.fr==-1)continue;
        if(mc==-1||t.sc.fr<mc){mc=t.sc.fr;tw=t.sc.sc;}
        else if(mc==t.sc.fr)tw+=t.sc.sc;
    }
    lb[z]=cmi;
    if(cmi==-1){
        abmc+=cost[z];
    }
    else if(cmi<=lev){
        if(cost[z]<mc||mc==-1){mc=cost[z];tw=1;}
        else if(cost[z]==mc)tw++;
    }
    if(cmi==lev){
        cmi=-1;
        abmc+=mc;
        abtw=(abtw*tw)%M;
        mc=-1;
        tw=1;
    }
    return {cmi,{mc,tw}};
}
void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,i,0);
    }
    cout<<abmc<<" "<<abtw;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}