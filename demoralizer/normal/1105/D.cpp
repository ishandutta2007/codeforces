#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
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
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

int n,m,p,gmr=1;
int sp[10],c[10],occ[1005][1005];
deque<pii> dq[10];deque<piii> bfs;
void solve(){
    cin>>n>>m>>p;
    for(int i=1;i<=p;i++)cin>>sp[i];
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]!='.')occ[i][j+1]=1;
            else continue;
            if(s[j]=='#')continue;
            dq[s[j]-'0'].pb({i,j+1});
            c[s[j]-'0']++;
        }
    }
    while(gmr){
        gmr=0;
        for(int i=1;i<=p;i++){
            int l=dq[i].size();
            while(l--){
                bfs.pb({0,dq[i].front()});
                dq[i].pop_front();
            }
            while(!bfs.empty()){
                piii cur=bfs.front();
                bfs.pop_front();
                if(cur.fr==sp[i])continue;//cout<<cur.sc.fr<<" "<<cur.sc.sc<<"\n";
                if(cur.sc.fr<n)if(!occ[cur.sc.fr+1][cur.sc.sc]){
                    occ[cur.sc.fr+1][cur.sc.sc]=1;
                    bfs.pb({cur.fr+1,{cur.sc.fr+1,cur.sc.sc}});
                    if(cur.fr+1==sp[i])dq[i].pb({cur.sc.fr+1,cur.sc.sc});
                    c[i]++;
                    gmr=1;
                }
                if(cur.sc.fr>1)if(!occ[cur.sc.fr-1][cur.sc.sc]){
                    occ[cur.sc.fr-1][cur.sc.sc]=1;
                    bfs.pb({cur.fr+1,{cur.sc.fr-1,cur.sc.sc}});
                    if(cur.fr+1==sp[i])dq[i].pb({cur.sc.fr-1,cur.sc.sc});
                    c[i]++;
                    gmr=1;
                }
                if(cur.sc.sc<m)if(!occ[cur.sc.fr][cur.sc.sc+1]){
                    occ[cur.sc.fr][cur.sc.sc+1]=1;
                    bfs.pb({cur.fr+1,{cur.sc.fr,cur.sc.sc+1}});
                    if(cur.fr+1==sp[i])dq[i].pb({cur.sc.fr,cur.sc.sc+1});
                    c[i]++;
                    gmr=1;
                }
                if(cur.sc.sc>1)if(!occ[cur.sc.fr][cur.sc.sc-1]){
                    occ[cur.sc.fr][cur.sc.sc-1]=1;
                    bfs.pb({cur.fr+1,{cur.sc.fr,cur.sc.sc-1}});
                    if(cur.fr+1==sp[i])dq[i].pb({cur.sc.fr,cur.sc.sc-1});
                    c[i]++;
                    gmr=1;
                }
            }
        }
    }
    for(int i=1;i<=p;i++){
        cout<<c[i]<<" ";
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