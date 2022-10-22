#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD2 1000000007
#define MOD 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int mod_pow(Int x, Int a, Int m = MOD){
    if(a == 0)return 1;
    Int res = mod_pow(x, a / 2, m);
    res = res * res % m;
    if(a % 2)res *= x;
    return res % m;
}

Int inv(Int x, Int m = MOD){
    return mod_pow(x, m-2, m);
}

Int n, m;
Int val[220000];
map<Int, Int> cnt[36][36];
int main(){
    cin >> n >> m;
    for(Int i = 0;i < n;i++){
        scanf("%lld", val+i);
    }
    for(Int i = 0;i < n;i++){
        Int mx = i;
        for(Int j = i;j < n;j++){
            if(val[mx] < val[j])mx = j;
        }
        swap(val[mx], val[i]);
        if(val[i] == 0)break;
        for(Int j = i+1;j < n;j++){
            val[j] = min(val[j], val[j] ^ val[i]);
        }
    }
    Int base = 0;
    while(base < n && val[base] > 0) base++;
    cnt[0][0][0] = 1;
    for(Int i = 0;i < base;i++){
        Int v = val[i];
        for(Int b = 0;b <= i;b++){
            for(auto p:cnt[i][b]){
                {
                    Int new_v = p.first;
                    Int shoot = 1LL << (34-i);
                    Int nb = b;
                    if(new_v >= shoot){
                        nb++;
                        new_v -= shoot;
                    }
                    (cnt[i+1][nb][new_v] += p.second) %= MOD;
                }
                {
                    Int new_v = v ^ p.first;
                    Int shoot = 1LL << (34-i);
                    Int nb = b;
                    if(new_v >= shoot){
                        nb++;
                        new_v -= shoot;
                    }
                    (cnt[i+1][nb][new_v] += p.second) %= MOD;
                }                
            }
        }        
    }
    vector<Int> ans(36, 0);
    for(Int b = 0;b <= 35;b++){
        for(auto p:cnt[base][b]){
            Int pcnt = 0;
            for(Int i = 0;i < 35;i++){
                if((p.first >> i)% 2)pcnt++;
            }
            (ans[pcnt + b] += p.second) %= MOD;
        }
    }

    Int rem = n - base;
    for(Int i = 0;i <= m;i++){
        cout << ans[i] * mod_pow(2, rem) % MOD << " ";
    }cout << endl;
    return 0;
}