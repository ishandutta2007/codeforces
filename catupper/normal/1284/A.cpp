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

int a, b;
string as[22], bs[22];
int q, x;

int main(){
    cin >> a >> b;
    for(int i = 0;i < a;i++)cin >> as[i];
    for(int i = 0;i < b;i++)cin >> bs[i];
    cin >> q;
    for(int i = 0;i < q;i++){
        cin >> x;x--;
        cout << as[x%a] << bs[x%b] << endl;
    }
    return 0;
}