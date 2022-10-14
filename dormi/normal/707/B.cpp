#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
bool bad[MAXN];
vector<pair<int,ll>> matrix[MAXN];


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;
    ll c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }
    for(int i=0;i<k;i++){
        cin>>a;
        bad[a]=true;
    }
    ll best=LLONG_MAX;
    for(int i=1;i<=n;i++){
        if(bad[i]){
            for(auto x:matrix[i]){
                if(!bad[x.first])best=min(best,x.second);
            }
        }
    }
    if(best==LLONG_MAX)printf("-1\n");
    else printf("%lli\n",best);
    return 0;
}