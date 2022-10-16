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
int T,n;
char s[MAXN];
vector<array<int,2>>ret;
void output(){
    cout<<"YES\n";
    for(auto p:ret)cout<<p[0]<<' '<<p[1]<<'\n';
}
void solve(){
    cin>>n>>(s+1);ret.clear();
    int cnt1=0,cnt2=0;
    rep(i,1,n)if(s[i]=='0')cnt1++;else cnt2++;
    if(odd(cnt2) || !cnt2){cout<<"NO\n";return;}
    if(!cnt1){rep(i,2,n)ret.push_back({1,i});output();return;}
    int pos=0;rep(i,1,n)if(s[i]=='0' && s[i+1]=='1'){pos=i;break;}if(!pos)pos=n;
    int cur=(pos<n)?(pos+1):1;
    while(1){
        int start=cur,end=(cur<n)?(cur+1):(1);
        while(end!=pos && s[end]=='0')end=(end<n)?(end+1):(1);
        end=(end>1)?(end-1):(n);
        ret.push_back({pos,end});
        while(start!=end){
            int nxt=(start<n)?(start+1):(1);
            ret.push_back({start,nxt});
            start=nxt;
        }
        cur=(end<n)?(end+1):(1);
        if(cur==pos)break;
    }
    output();
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}