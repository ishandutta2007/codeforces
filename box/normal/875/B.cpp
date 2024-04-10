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

int cal(string x){
    rep(i,x.size()+1){
        int cnt=0;
        rep(j,x.size()-1)
            if(x[j]=='1'&&x[j+1]=='0')
                swap(x[j],x[j+1]),cnt++;
        if(!cnt)return i;
    }
    return -1;
}

bool x[300005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    int dc=0,cnt=0;
    cout<<1;
    rep(i,n){
        int v;cin>>v;
        x[v]=1;cnt++;
        while(dc!=n&&x[n-dc]){
            dc++;cnt--;
        }
        cout<<' '<<cnt+1;
    }
}