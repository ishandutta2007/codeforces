#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=510;
int T,n,a[MAXN],cur;
map<int,int>f;
vector<array<int,2> >op;
vector<int>ret;
void rev(int k){
    rep(i,1,k)op.push_back({cur+k+i-1,a[i]});
    ret.push_back(2*k);
    reverse(a+1,a+1+k);
    cur+=2*k;
}
void solve(){
    f.clear();op.clear();ret.clear();
    cin>>n;
    rep(i,1,n)cin>>a[i],f[a[i]]++;
    rep(i,1,n)if(odd(f[a[i]])){
        cout<<-1<<endl;return;
    }
    cur=0;
    rep(i,1,n){
        int pos=0;
        rep(j,1,n-i+1)if(!pos||a[pos]<a[j])pos=j;
        rev(pos);
        rev(n-i+1);
    }
    rep(i,1,n/2)ret.push_back(2);
    cout<<(int)(op.size())<<endl;
    for(auto p:op)cout<<p[0]<<' '<<p[1]<<endl;
    cout<<(int)(ret.size())<<endl;
    for(auto p:ret)cout<<p<<' ';cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}