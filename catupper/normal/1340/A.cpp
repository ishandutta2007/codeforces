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

int a[110000];

void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++)scanf("%d", &a[i]);
    int minimum = 1;
    while(n){
        int last = a[n-1];
        for(int i = last;i >= minimum;i--){
            if(a[n-1-last+i] != i){
                puts("No");
                return;
            }
        }
        n = n-1-last+minimum;
        minimum = last + 1;
    }
    puts("Yes");
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--)solve();
    return 0;
}