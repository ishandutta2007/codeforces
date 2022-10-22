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

char a[110000];
char b[110000];
int n, t;

void solve(){
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    int reversed = 0;
    int flipped = 0;
    int l = 0, r = n-1;
    vector<int> queries;
    for(int i = n-1;i >= 0;i--){
        if((!reversed && (a[l] ^ flipped) == b[i])){
            queries.push_back(1);
            a[l] ^= 1;
        }
        else if (reversed && (a[r] ^ flipped) == b[i]){
            queries.push_back(1);
            a[r] ^= 1;
        }
        queries.push_back(i+1);
        if(!reversed)l++;
        else r--;
        reversed ^= 1;
        flipped ^= 1;        
    }
    printf("%d", int(queries.size()));
    for(auto q: queries){
        printf(" %d", q);
    }puts("");
}

int main(){
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}