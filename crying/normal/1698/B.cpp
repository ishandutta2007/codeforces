#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,k;
int a[MAXN];
void solve(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];
    if(k==1){
        cout<<(n-1)/2<<endl;
        return;
    }
    int cnt=0;
    rep(i,2,n-1)if(a[i]>a[i-1]+a[i+1])cnt++;
    cout<<cnt<<endl;
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}