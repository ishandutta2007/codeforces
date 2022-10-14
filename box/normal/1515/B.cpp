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
    set<int>sqs;
    for(int i=1;i*i<=1500000000;i++)sqs.insert(i*i);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n%2==0&&sqs.count(n/2))cout<<"YES"<<endl;
        else if(n%4==0&&sqs.count(n/4))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}