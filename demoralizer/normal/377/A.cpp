#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
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

int n,m,k;
string s[600];
map<pii,vc<pii> > v;
map<pii,int> vis;
void dfs(pii z){
    if(!k)return;
    vis[z]=1;
    for(pii i:v[z]){
        if(vis[i])continue;
        dfs(i);
        if(!k)return;
    }
    s[z.fr][z.sc]='X';
    k--;
}
void solve(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int x=-1,y=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'){
                x=i;y=j;
                if(i+1<n&&s[i+1][j]=='.'){
                    v[{i,j}].pb({i+1,j});
                    v[{i+1,j}].pb({i,j});
                }
                if(i-1>=0&&s[i-1][j]=='.'){
                    v[{i,j}].pb({i-1,j});
                    v[{i-1,j}].pb({i,j});
                }
                if(j+1<m&&s[i][j+1]=='.'){
                    v[{i,j}].pb({i,j+1});
                    v[{i,j+1}].pb({i,j});
                }
                if(j-1>=0&&s[i][j-1]=='.'){
                    v[{i,j}].pb({i,j-1});
                    v[{i,j-1}].pb({i,j});
                }
            }
        }
    }
    dfs({x,y});
    for(int i=0;i<n;i++){
        cout<<s[i]<<"\n";
    }
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