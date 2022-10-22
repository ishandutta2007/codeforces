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

char a[110000], b[110000];
int n;
bool go[22][22];
void solve(){
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    for(int i = 0;i < 22;i++){
        for(int j = 0;j < 22;j++){
            go[i][j] = false;
        }
    }
    for(int i = 0;i < n;i++){
        if(a[i] > b[i]){
            puts("-1");
            return;
        }
        if(a[i] < b[i]){
            go[a[i]-'a'][b[i]-'a'] = true;
        }
    }
    int cnt = 0;
    for(int i = 0;i < 22;i++){
        int nxt = i;
        while(nxt < 22 && !go[i][nxt])nxt++;
        if(nxt == 22)continue;
        for(int j = nxt + 1;j < 22;j++){
            go[nxt][j] |= go[i][j];
        }
        cnt++;
    }
    printf("%d\n", cnt);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)solve();
    return 0;
}