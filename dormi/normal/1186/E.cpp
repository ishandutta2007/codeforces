#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e3+1;
ll arr[MAXN][MAXN];
ll n,m;
bool inver(ll a){
    return __builtin_popcountll(a)%2;
}
ll invercnt(ll a){
    if(a%2)return (a+1)/2;
    return a/2+inver(a);
}
ll solve(ll x, ll y){
    if(x<0||y<0)return 0;
    ll curfield=(inver(x/n)^inver(y/m)?((x%n)+1)*((y%m)+1)-arr[x%n][y%m]:arr[x%n][y%m]);
    ll fieldx=x/n-1,fieldy=y/m-1;
    if(fieldx>=0&&fieldy>=0){
        ll numinverted=invercnt(fieldy)*(fieldx+1-invercnt(fieldx))+(fieldy+1-invercnt(fieldy))*invercnt(fieldx);
        curfield+=((fieldx+1)*(fieldy+1)-numinverted)*arr[n-1][m-1]+numinverted*(n*m-arr[n-1][m-1]);
    }
    if(fieldx>=0)curfield+=(fieldx+1-(inver(fieldy+1)?fieldx+1-invercnt(fieldx):invercnt(fieldx)))*arr[n-1][y%m]+(inver(fieldy+1)?fieldx+1-invercnt(fieldx):invercnt(fieldx))*(n*((y%m)+1)-arr[n-1][y%m]);
    if(fieldy>=0)curfield+=(fieldy+1-(inver(fieldx+1)?fieldy+1-invercnt(fieldy):invercnt(fieldy)))*arr[x%n][m-1]+(inver(fieldx+1)?fieldy+1-invercnt(fieldy):invercnt(fieldy))*(((x%n)+1)*m-arr[x%n][m-1]);
    return curfield;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>n>>m>>q;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        for(int j=0;j<m;j++){
            arr[i][j]=(i-1>=0?arr[i-1][j]:0)+(j-1>=0?arr[i][j-1]:0)+(a[j]=='1')-(i-1>=0&&j-1>=0?arr[i-1][j-1]:0);
        }
    }
    ll x1,x2,y1,y2;
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        x1-=1,x2-=1,y1-=1,y2-=1;
        printf("%lli\n",solve(x2,y2)-solve(x1-1,y2)-solve(x2,y1-1)+solve(x1-1,y1-1));
    }
    return 0;
}