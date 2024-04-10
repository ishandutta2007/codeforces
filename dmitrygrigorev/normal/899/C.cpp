#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sum = (n * (n+1)) / 2;
    vector<int> v;
    int now = 0;
    for (int i=n; i >= 1; i--){
        int var = now+i;
        if (2*var <= sum){
            v.push_back(i);
            now += i;
        }
    }
    cout << abs(sum - 2*now) << endl;
    cout << v.size() << " ";
    for (int i=0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}