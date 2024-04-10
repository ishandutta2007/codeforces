#include <bits/stdc++.h>
using namespace std;

#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define endl '\n'
#define int long long

const int N = 1000000007;
const int N2 = 998244353;
const int INF = 1000000000000000000;

vector<vector<int>> dp;
vector<vector<int>> val;
vector<vector<int>> pf;
vector<vector<int>> par;
vector<int> ans;
int n;

int pref(int l,int r) {
    if (r<l) {
        return 0;
    }
    int ans=(pf[r+1][n]-pf[l][n])-(pf[r+1][r+1]-pf[l][r+1]-pf[r+1][l]+pf[l][l]);
    return ans;
}

int rec(int l,int r) {
    if (r<l) {
        return 0;
    }
    if (r==l) {
        par[l][r]=l;
        return 0;
    }
    if (dp[l][r]!=-1) {
        return dp[l][r];
    }
    int ans=INF;
    for (int t1=l;t1<=r;t1++) {
        int cur=rec(l,t1-1)+pref(l,t1-1)+rec(t1+1,r)+pref(t1+1,r);
        ans=min(ans,cur);
        if (ans==cur) {
            par[l][r]=t1;
        }
    }
    dp[l][r]=ans;
    return ans;
}

void rec2(int l,int r,int up) {
    if (r<l) {
        return;
    }
    if (ans[par[l][r]]!=-1) {
        return;
    }
    ans[par[l][r]]=up+1;
    rec2(l,par[l][r]-1,par[l][r]);
    rec2(par[l][r]+1,r,par[l][r]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input12.txt","r",stdin);
    // freopen("ans12.txt","w",stdout);
    cin >> n;
    dp.resize(n,vector<int>(n,-1));
    pf.resize(n+1,vector<int>(n+1));
    val.resize(n,vector<int>(n));
    par.resize(n,vector<int>(n));
    ans.resize(n,-1);
    for (int t1=0;t1<n;t1++) {
        for (int t2=0;t2<n;t2++) {
            cin >> val[t1][t2];
        }
    }
    for (int t1=0;t1<n;t1++) {
        for (int t2=0;t2<n;t2++) {
            pf[t1+1][t2+1]=val[t1][t2]+pf[t1+1][t2]+pf[t1][t2+1]-pf[t1][t2];
        }
    }
    rec(0,n-1);
    rec2(0,n-1,-1);
    for (int t1=0;t1<n;t1++) {
        cout << ans[t1] << " ";
    }
    cout << endl;
    return 0;
}