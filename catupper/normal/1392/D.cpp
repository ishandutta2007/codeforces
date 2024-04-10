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
char str[220000];
void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int start = -1;
    for(int i = 0;i < n;i++){
        if(str[i] != str[(i+n-1) % n])start = i;
    }
    if(start == -1){
        printf("%d\n", (n - 1) / 3 + 1);
        return;
    }
    int run = 0;
    int ans = 0;
    int last = 'C';
    for(int i = 0;i < n;i++){
        int ind = (start + i) % n;
        if(str[ind] == last)run++;
        else{
            ans += run / 3;
            last = str[ind];
            run = 1;
        }
    }
    ans += run / 3;
    printf("%d\n", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)solve();
    return 0;
}