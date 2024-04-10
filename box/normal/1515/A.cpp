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
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int>ar(n);
        rep(i,n)cin>>ar[i];
        int s=0;
        rep(i,n){
            s+=ar[i];
            if(s==x&&i!=n-1){
                swap(ar[i],ar[i+1]);
                s=x+1;
            }
        }
        if(s==x)cout<<"NO"<<endl;
        else{
            cout<<"YES\n";
            rep(i,n)cout<<ar[i]<<" \n"[i==n-1];
        }
    }
}