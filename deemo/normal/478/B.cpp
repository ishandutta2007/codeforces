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

int main(){
    long long n , m;
    cin >> n >> m;
    long long k = n / m;//har gorooh inghadr!
    long long ans = 0;
    ans += (long long)((long long)(m) * (long long)(k * (long long)(k - 1) / (long long)(2)));
    ans += (n % m) * k;
    cout << ans << " ";

    n = n - m + 1;
    ans = 0;
    ans = (long long)((long long)(n * (long long)(n - 1)) / (long long)(2));
    cout << ans << endl;

    return 0;
}