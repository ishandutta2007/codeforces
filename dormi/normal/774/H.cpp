#include <bits/stdc++.h>
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
const int MAXN=2000;
int arr[MAXN];
int cur[MAXN];
int ans[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    rep(i,0,n){
        sc(arr[i]);
    }
    int cc=0;
    int loc=0;
    for(int i=n-1;i>=0;i--){
        while(arr[i]-cur[i]>0){
            for(int j=i;j>=0;j--){
                cur[j]+=i-j+1;
            }
            rep(j,0,i+1){
                ans[loc++]=cc;
            }
            cc=(cc+1)%26;
        }
    }
    rep(i,0,n)pr((char)('a'+ans[i]));
    return 0;
}