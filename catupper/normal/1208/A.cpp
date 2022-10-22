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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int t, a, b, n;

int main(){
    cin >> t;
    for(int i = 0;i < t;i++){
        cin >> a >> b >> n;
        n %= 3;
        Int ans;
        if(n == 0)ans = a;
        if(n == 1)ans = b;
        if(n == 2)ans = a ^ b;
        cout << ans << endl;
    }
    return 0;
}