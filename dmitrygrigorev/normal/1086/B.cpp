#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    vector<int> step(n);
    fill(step.begin(), step.end(), 0);
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        step[a-1]++, step[b-1]++;
    }
    if (n==2){
        cout << s;
        return 0;
    }
    int l = 0;
    for (int i=0;i<n;i++) if (step[i] == 1) l++;
    double res = 2.;
    res *= (double) s;
    res /= (double) l;
    cout.precision(20);
    cout << res;
    return 0;
}