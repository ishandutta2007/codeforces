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
#include<cstring>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;


Int ans = 0;
vector<P> stk = {{INF, 0}};
vector<int> run_length;
char s[1100000];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    int zero_cnt = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == '0')zero_cnt++;
        else{
            run_length.push_back(zero_cnt);
            zero_cnt = 0;
        }
    }

    if(run_length.empty()){
        cout << zero_cnt << endl;
        return 0;
    }
    for(auto l:run_length){
        if(stk.back() == P(INF, 0)){
            stk.push_back({l, l+1});
            continue;
        }
        Int last = -1;
        Int val = 0;
        Int merged = 0;
        while(stk.back().first < l){
            (val += stk.back().second * (l - last) % MOD) %= MOD;            
            (merged += stk.back().second) %= MOD;
            last = stk.back().first;
            stk.pop_back();
        }
        (val += stk.back().second * (l-last) % MOD) %= MOD;
        (stk.back().second += merged) %= MOD;
        stk.push_back({l, val});
    }
    for(auto x:stk)(ans += x.second) %= MOD;
    (ans *= 1 + zero_cnt) %= MOD;
    cout << ans << endl;
    return 0;
}