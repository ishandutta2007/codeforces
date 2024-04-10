#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll N, M, A;
    cin >> N >> M >> A;
    ll w = (N + A - 1) / A;
    ll h = (M + A - 1) / A;
    cout << w * h << '\n';
    return 0;
}