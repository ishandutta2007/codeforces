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

Int field[25][25];
Int comb[51][51];
Int way[51][51];
int main(){
    for(int i = 1;i < 51;i++){
        for(int j = 0;j <= i;j++){
            if(j == 0)comb[i][j] = 1;
            else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
        }
    }
    
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){          
            if(j == n-1)field[i][j] = 0;
            else if(i == 0)field[i][j] = 1LL << j;
            else field[i][j] = field[i-1][j+1] + (1LL << (i+j-1));
            printf("%lld ", field[i][j]);
        }puts("");
    }
    fflush(stdout);
    int q;
    scanf("%d", &q);
    while(q--){
        Int x;
        scanf("%lld", &x);
        int nx = 1, ny = 1;
        for(int i = 0;i < n * 2 - 2;i++){
            printf("%d %d\n", nx, ny);
            if(x % 2 == 0)nx++;
            else ny++;
            x  /= 2;
        }
        printf("%d %d\n", nx, ny);
        fflush(stdout);
    }
    
    return 0;
}