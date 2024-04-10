#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=100005;

int n;
string str;

void ahcorz(){
    cin >> n >> str;
    if(count(all(str),'0')&1){
        cout << "-1\n";
        return;
    }
    vector<int> vec;
    rep(i,0,n) if(str[i*2]^str[i*2+1]){
        if(sz(vec)&1){
            if(str[i*2]=='1') vec.pb(i*2);
            else vec.pb(i*2+1);
        }
        else{
            if(str[i*2]=='0') vec.pb(i*2);
            else vec.pb(i*2+1);
        }
    }
    cout << sz(vec) << ' ';
    for(auto i: vec) cout << i+1 << ' ';
    cout << "\n";
    rep(i,0,n) cout << i*2+1 << ' ';
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--) ahcorz();
    
}