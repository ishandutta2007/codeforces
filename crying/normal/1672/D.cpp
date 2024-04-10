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
int T,n,a[MAXN],b[MAXN];
int bucket[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    rep(i,1,n)bucket[i]=0;
    int i=1,j=1;
    while(j<=n){
        if(i<=n && j<=n && a[i]==b[j]){
            i++;j++;
            continue;
        }
        if(bucket[b[j]] && b[j-1]==b[j]){
            bucket[b[j]]--;j++;
            continue;
        }
        if(i<=n){
            bucket[a[i]]++;i++;
            continue;
        }
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}