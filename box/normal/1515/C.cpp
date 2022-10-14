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

int ans[100005],sm[100005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int m,n,x;cin>>n>>m>>x;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        rep1(i,m)sm[i]=0,pq.push({0,i});
        cout<<"YES"<<endl;
        rep1(i,n){
            int x;cin>>x;
            cout<<pq.top().second<<" \n"[i==n];
            auto [a,y]=pq.top();pq.pop();
            pq.push({a+x,y});
        }
    }
}