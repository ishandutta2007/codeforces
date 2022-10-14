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

string solve(string _s) {
    string s;
    s+=_s[0];
    rep1(i,_s.size()-1){
        s+='#';
        s+=_s[i];
    }
    int n=s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    int th=0;
    while(th<n-th-1&&s[th]==s[n-th-1])th++;
    int bl=-1,bpos=-1;
    rep(i,n){
        int z=d1[i];
        int L=i-d1[i]+1,R=i+d1[i]-1;
        if(L<=th&&R<n-L){
            int le=(R+1)+L;
            if(le>bl){
                bpos=i;
                bl=le;
            }
        }
    }
    string re;
    int i=bpos;
    int z=d1[i];
    int L=i-d1[i]+1,R=i+d1[i]-1;
    // cout<<s<<' '<<L<<' '<<R<<' '<<n-L<<' '<<th<<endl;
    rep(i,R+1)re+=s[i];
    iter(i,n-L,n)re+=s[i];
    string r2;
    for(char c:re)if(c!='#')r2+=c;
    return r2;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string a;cin>>a;
        string b=a;reverse(all(a));
        string x=solve(a),y=solve(b);
        if(x.length()<y.length())x=y;
        cout<<x<<'\n';
        // cout<<solve(a)<<' '<<solve(b)<<endl;
    }
}