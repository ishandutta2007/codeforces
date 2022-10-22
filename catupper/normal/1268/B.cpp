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

Int a, n;

int main(){
    cin >> n;
    Int sum = 0;
    Int odd = 0;
    for(int i = 0;i < n;i++){
        cin >> a;
        sum += a;
        int o = a / 2;
        if(i % 2) o = a - o;
        odd += o;
    }
    cout << min(odd, sum - odd) << endl;
    return 0;
}