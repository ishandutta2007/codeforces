#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<double> ys;
    cout.precision(20);
    for (int i=0; i < n; i++){
        double answer = r;
        for (int j=0; j < i; j++){
            int S = 4*r*r;
            int X = abs(v[i] - v[j]) * abs(v[i] - v[j]);
            int ost = S - X;
            //if (i == 2 && j == 1) cout << ost << endl;
            if (ost < 0) continue;
            double D = sqrt((double) ost);
            double V = D + (double) ys[j];
            answer = max((double) answer, V);
        }
        ys.push_back(answer);
    }
    for (int i=0;i<n; i++) cout << ys[i] << " ";
    return 0;
}