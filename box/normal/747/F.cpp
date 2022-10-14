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

ll bino[17][17];
ll dp[17],ndp[17];
void cnt(vector<int>z){
    assert(z.size()==16);
    rep(i,12)dp[i]=0;
    dp[0]=1;
    for(int x:z){
        rep(i,12)ndp[i]=0;
        rep(i,x+1)rep(j,12-i)ndp[i+j]+=bino[i+j][j]*dp[j];
        rep(i,12)dp[i]=ndp[i];
    }
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    bino[0][0]=1;
    rep1(i,12)rep(j,i+1){
        bino[i][j]=bino[i-1][j];
        if(j)bino[i][j]+=bino[i-1][j-1];
    }
    ll n;
    int t;
    cin>>n>>t;
    vector<int>st(16,t);
    st[0]--;
    cnt(st);
    vector<ll>q2(dp,dp+17);
    st[0]++;
    cnt(st);
    vector<ll>q1(dp,dp+17);
    int L=0;
    // rep(i,11)cout<<dp[i]<<endl;
    rep(i,12){
        ll cn=q1[i];if(i)cn-=q2[i-1];
        if(n>=cn)n-=cn;
        else{L=i;break;}
    }
    rep(d,L){
        int r=0;
        rep(i,16){
            // cout<<i<<' '<<st[i]<<endl;
            if(!(d+i))continue;
            if(!st[i])continue;
            st[i]--;r=i;
            cnt(st);
            // cout<<dp[L-d-1]<<endl;
            if(dp[L-d-1]<=n){
                n-=dp[L-d-1];
                st[i]++;
            }else break;
        }
        // cout<<r<<endl;
        cout<<"0123456789abcdef"[r];
    }
    // if(t==2)cout<<n<<endl;
}