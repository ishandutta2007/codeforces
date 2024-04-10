#include <bits/stdc++.h>
#define android ios

using namespace std;

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long s, v1, t1, v2, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    long long a = s * v1 + 2 * t1;
    long long b = s * v2 + 2 * t2;
    if (a < b)
        cout << "First" << endl;
    else if (a == b)
        cout << "Friendship" << endl;
    else
        cout << "Second" << endl;
    return 0;
}