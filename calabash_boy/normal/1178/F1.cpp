#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 * 2 + 100;
const int maxm = 1e6 + 100;
typedef long long ll;
const ll mod = 998244353;
ll dp[maxn][maxn];
int n,m;
int N;
int a[maxm];
int A[maxm];
int Left[maxn];
int Right[maxn];
ll solve(int L, int R){
    if (dp[L][R] != -1)return dp[L][R];
    if (L > R)return dp[L][R] = 1;
    int Lbound = INT_MAX;
    int Rbound = 0;
    for (int i=L;i<=R;i++){
        Lbound = min(Lbound,Left[A[i]]);
        Rbound = max(Rbound,Right[A[i]]);
    }
    if (Lbound < L || Rbound > R){
        return dp[L][R] = 0;
    }
    int num =  INT_MAX;
    for (int i= L; i <= R;i ++){
        num = min(num,A[i]);
    }
    bool all_same = true;
    for (int i=L;i<=R;i++){
        if (A[i] != num)all_same = false;
    }
    if (all_same){
        return dp[L][R] = 1;
    }
    int LL = INT_MAX;
    int RR = 0;
    for (int i = L;i <= R;i ++){
        if (A[i] == num){
            LL = min(LL,i);
            RR = max(RR,i);
        }
    }
    ll ans = 1;
    vector<int> keyP(0);
    for (int i=L;i<=R;i++){
        if (A[i] == num){
            keyP.push_back(i);
        }
    }
    for (int i=0;i+1<keyP.size();i++){
        int left = keyP[i] + 1;
        int right = keyP[i+1] - 1;
        if (left <= right){
            (ans *= solve(left,right)) %= mod;
        }
    }
    ll ansL = 0;
    for (int i = L;i <=LL;i ++){
        (ansL += solve(i,LL - 1) * solve(L,i-1)) %= mod;
    }
    ll ansR = 0;
    for (int i=RR;i <= R;i ++){
        (ansR += solve(RR + 1,i) * solve(i + 1,R)) %= mod;
    }
   // cerr<<"solve("<<L<<" , "<<R<<"): "<<ans<<" "<<ansL<<" "<<ansR<<endl;
    return dp[L][R] = 1ll * ans * ansL % mod * ansR % mod;
}
void debug(){
    cerr<<"N = "<<N<<endl;
    for (int i=1;i<=N;i++){
        cerr<<A[i]<<" ";
    }
    cerr<<endl;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            cerr<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        scanf("%d",a+i);
    }
    for (int i=1,j=1;i<=m;i=j){
        while (j <= m && a[j] == a[i])j++;
        A[++N] = a[i];
    }
    for (int i=1;i<=n;i++){
        Left[i] = INT_MAX;
        Right[i] = 0;
    }
    for (int i=1;i<=N;i++){
        Left[A[i]] = min(Left[A[i]],i);
        Right[A[i]] = max(Right[A[i]],i);
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=N;j++){
            int ll = max(Left[i],Left[j]);
            int rr = min(Right[i],Right[j]);
            if (ll <= rr){
                if (ll == Left[i] && rr == Right[i]
                    || ll == Left[j] && rr == Right[j]);
                else{
                    cout<<0<<endl;
                    return 0;
                }
            }
        }
    }
    assert(N < maxn);
    for (int i=0;i<=N + 2;i++){
        for (int j=0;j<=N + 2;j++){
            dp[i][j] = -1;
        }
    }
    cout<<solve(1, N)<<endl;
  //  debug();
    return 0;
}
/*

3 3
1 2 3
 
5
*/