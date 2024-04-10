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

string s;
bool us[500005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    stack<int>z;
    int n,k;cin>>n>>k;k/=2;
    cin>>s;
    rep(i,n){
        if(s[i]=='(')z.push(i);
        else{
            if(k){
                us[i]=1;
                us[z.top()]=1;
                k--;
            }
            z.pop();
        }
    }
    rep(i,n)if(us[i])cout<<s[i];
}