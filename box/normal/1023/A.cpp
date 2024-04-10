// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
    int n,m;
    cin>>n>>m;
    string a,b;cin>>a>>b;
    string pre,suf;bool mode=0;
    for(char c:a){
        if(c=='*')mode=1;
        else if(mode) suf+=c;
        else pre+=c;
    }
    if(mode==0&&pre!=b)cout<<"NO\n";
    else if(pre.size()+suf.size()>m)cout<<"NO\n";
    else{
        if(pre!=b.substr(0,pre.size()))cout<<"NO\n";
        else if(suf!=b.substr(m-suf.size()))cout<<"NO\n";
        else cout<<"YES\n";
    }
}