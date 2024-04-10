#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    //freopen("1.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    int st=1;
    for (int i=2; i < n; i*=2){
        int N = i;
        for (int j=0; j < n; j += N){
            int k = j+N-1;
            if (a >= j && a <= k && b >= j && b <= k){
                cout << st << endl;
                return 0;
            }
        }
        st++;
    }
    cout << "Final!" << endl;
    return 0;
}