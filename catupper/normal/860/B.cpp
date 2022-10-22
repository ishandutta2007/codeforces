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
#include<unordered_map>
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

unordered_map<Int, int> cnt;
char str[77000][10];



int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%s", str[i]);
        for(int j = 0;j < 9;j++){
            Int x = 1;
            for(int k = j;k >= 0;k--){
                x *= 10;
                x += str[i][k] - '0';
                cnt[x]++;
            }
        }
    }
    for(int i = 0;i < n;i++){
        unordered_map<Int, int> cnt2;
        Int ans = LINF;
        for(int j = 0;j < 9;j++){
            Int x = 1;
            for(int k = j;k >= 0;k--){
                x *= 10;
                x += str[i][k] - '0';
                cnt2[x]++;
                if(cnt2[x] == cnt[x]){
                    ans = min(ans, x);
                }
            }
        }
        while(ans != 1){
            putchar('0' + (ans % 10));
            ans /= 10;
        }
        puts("");
    }
    
    return 0;
}