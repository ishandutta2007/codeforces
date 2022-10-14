#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
vector<lli> arr[2][2];
const int MAXN=1e5+1;
int overlap[2][MAXN];
pll lec[2][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    lli a,b;
    rep(i,0,n){
        sc(a,b);
        lec[0][i]={a,b};
        arr[0][0].push_back(a);
        arr[0][1].push_back(b);
        sc(a,b);
        lec[1][i]={a,b};
        arr[1][0].push_back(a);
        arr[1][1].push_back(b);
    }
    rep(i,0,2) {
        sort(arr[i][0].begin(),arr[i][0].end());
        sort(arr[i][1].begin(),arr[i][1].end());
        rep(j,0,n){
            overlap[i][j]=n-(lower_bound(arr[i][1].begin(),arr[i][1].end(),lec[i][j].first)-arr[i][1].begin())-(n-(upper_bound(arr[i][0].begin(),arr[i][0].end(),lec[i][j].second)-arr[i][0].begin()))-1;
        }
    }
    rep(i,0,n){
        if(overlap[0][i]!=overlap[1][i]){
            prl("NO");
            return 0;
        }
    }
    prl("YES");
    return 0;
}