#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
#define MOD 1000000007ull

//#define int ll

char s[5005];

long long DP[5005][5005];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
    //memset(DP, 255, sizeof DP);
    rep(i, n) 
        cin >> s[i];
    long long ans = 1, nsum = 0;
    DP[0][0] = 1;
    iter(i, 1, n) {
        ans = 0;
        for(int k=n-1; k>=0; k--) {
            nsum = (nsum + DP[i-1][k]) % MOD;
            if(s[i-1] == 'f') DP[i][k] = k?DP[i-1][k-1]:0;
            else DP[i][k] = nsum;
            if(i == n-1) ans = (ans + DP[i][k]) % MOD;
        }
        nsum = 0;
    }
    cout << (s[n-1]!='f')*ans << endl;
}