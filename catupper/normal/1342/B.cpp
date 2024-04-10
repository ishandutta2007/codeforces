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

void solve(){
    string s;
    int cnt[2] = {0,0};
    cin >> s;
    for(auto c:s){
        cnt[c-'0']++;
    }
    if(cnt[0] == 0){
        for(int i = 0;i < 2*s.size();i++)printf("1");
        puts("");
        return;
    }
    if(cnt[1] == 0){
        for(int i = 0;i < 2*s.size();i++)printf("0");
        puts("");
        return;
    }
    for(int i = 0;i < s.size();i++)printf("01");
    puts("");
    
}

int main(){
    Int t;
    cin >> t;
    while(t--)solve();
    return 0;
}