#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n >> a >> b;
    int i = 0;
    while (true){
        int ost = n-i*a;
        if (ost < 0) break;
        if (ost % b == 0){
            int j = ost / b;
            int st = 1;
            for (int I=0;I<i;I++){
                for (int J=0; J < a-1; J++) cout << st+J+1 << " ";
                cout << st << " ";
                st += a;
            }
            for (int I=0;I<j;I++){
                for (int J=0; J < b-1; J++) cout << st+J+1 << " ";
                cout << st << " ";
                st += b;
            }
            return 0;
        }
        i++;
    }
    cout << -1 << endl;
}