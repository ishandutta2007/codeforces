#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define INV2 (MOD/2+1)
#define MAXN 100005

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int binpow(int a, long long b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll*res * a % MOD;
        a = 1ll*a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n;
int arr[MAXN];
vector<pair<int, int>> goodnums;
int ans;

int calc(vector<pair<int, int>> tmp){
    int m = tmp.size();
    int sum = 0, sum2 = 0, prod;
    long long cnt = 0;
    for(int i = 0; i<m; i++){
        inc(sum, mul(tmp[i].second, tmp[i].first));
        inc(sum2, mul(tmp[i].second, mul(tmp[i].first, tmp[i].first)));
        cnt += tmp[i].second;
    }
    if(cnt <= 1) return 0;
    prod = sub(mul(sum, sum), sum2);
    // cout << mul(mul(sum, sum), mul((int)((cnt-1)%MOD), binpow(2, cnt-2))) << endl;
    int p1; if(cnt == 2) p1 = 1; else p1 = mul((int)(cnt%MOD), binpow(2, cnt-3));
    int p2 = mul((int)((cnt-1)%MOD), binpow(2, cnt-2));
    return add(mul(sum2, p2), mul(prod, p1));
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, f; cin >> a >> f;
        arr[a] = f;
    }
    for(int i = 1; i<MAXN; i++){
        int tmp = i;
        int cnt = 0; bool f = 1;
        for(int j = 2, end = sqrt(tmp)+5; j<end; j++){
            int pcnt = cnt;
            while(tmp%j == 0) cnt++, tmp/=j;
            if(cnt-pcnt >= 2){
                f = 0; break;
            }
        }
        if(!f) continue;
        if(tmp != 1) cnt++;
        goodnums.push_back({i, (cnt%2?MOD-1:1)});
    }
    for(auto x : goodnums){
        vector<pair<int, int>> tmp;
        for(int i = x.first; i<MAXN; i+=x.first) tmp.push_back({i, arr[i]});
        inc(ans, mul(calc(tmp), x.second));
    }
    cout << ans << endl;
}