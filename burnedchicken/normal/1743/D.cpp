#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=1000005,mod=998244353;

int n;
string str;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> str;
    if(count(all(str),'1')==0){
        cout << "0\n";
        return 0;
    }
    reverse(all(str));
    while(str.back()=='0') str.pop_back();
    reverse(all(str));
    string res=str;
    rep(i,0,n){
        string tmp=str;
        rep(j,0,n-i) tmp[i+j]|=str[j];
        res=max(res,tmp);
        if(str[i]=='0') break;
    }
    cout << res << "\n";
}