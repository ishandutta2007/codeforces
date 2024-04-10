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

int cal(int n){
    int ans=0;
    while(n){
        ans+=n%10;
        n/=10;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    vector<int>r;
    int m=max(1,n-1000);
    iter(i,m,n+1){
        if(cal(i)+i==n)r.push_back(i);
    }
    cout<<r.size()<<endl;
    for(int i:r)cout<<i<<' ';
}