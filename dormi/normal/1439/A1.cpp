#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=101;
string arr[MAXN];
vector<pii> all={{1,1},{1,2},{2,1},{2,2}};
void flip(int i, int j){
    if(arr[i][j]=='1')arr[i][j]='0';
    else arr[i][j]='1';
}
vector<vector<pii>> topr;
void getflips(pii a){
    vector<pii> te;
    for(auto x:all)if(x!=a)te.push_back(x);
    topr.push_back(te);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        topr=vector<vector<pii>>();
        for(int i=1;i<=n;i++)cin>>arr[i],arr[i]="1"+arr[i];
        for(int i=n;i>=3;i--)for(int j=m;j>=3;j--)if(arr[i][j]=='1'){
            topr.push_back({{i,j},{i-1,j},{i,j-1}});
            flip(i,j),flip(i-1,j),flip(i,j-1);
        }
        for(int i=n;i>=3;i--)for(int j=1;j<=2;j++)if(arr[i][j]=='1'){
            topr.push_back({{i,j},{i-1,1},{i-1,2}});
            flip(i,j),flip(i-1,1),flip(i-1,2);
        }
        for(int i=m;i>=3;i--)for(int j=1;j<=2;j++)if(arr[j][i]=='1'){
            topr.push_back({{j,i},{1,i-1},{2,i-1}});
            flip(j,i),flip(1,i-1),flip(2,i-1);
        }
        int am=0;
        for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(arr[i][j]=='0')am++;
        if(am%2){for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(arr[i][j]=='0')getflips({i,j});}
        else for(int i=1;i<=2;i++)for(int j=1;j<=2;j++)if(arr[i][j]=='1')getflips({i,j});
        printf("%d\n",sz(topr));
        for(auto x:topr)for(int i=0;i<3;i++)printf("%d %d%c",x[i].first,x[i].second," \n"[i==2]);
    }
    return 0;
}