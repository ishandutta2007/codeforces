#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;

int a , b , n , m;
int ans;

int main(){
    cin >> n >> m >> a >> b;
    ans = n * a;
    ans = min(ans , (n / m) * b + (n % m) * a);
    ans = min(ans , int(ceil(double(n) / double(m))) * b);
    cout << ans << endl;
    return 0;
}