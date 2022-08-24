#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
int INF = 2e18;
signed main(){
    int n, m, c;
    cin >> n >> m >> c;
    int V = c / 2;
    vector<int> x;
    for (int i=0; i < n; i++) x.push_back(-1);
    int var = 0;
    while (true){
        if (var == n){
            return 0;
        }
        int A;
        cin >> A;
        if (A <= V){
            for (int i=0; i < n; i++){
                if (x[i] == -1){
                    x[i] = A;
                    var++;
                    cout << i+1 << endl;
                    cout.flush();
                    break;
                }
                if (x[i] > A){
                    x[i] = A;
                    cout << i+1 << endl;
                    cout.flush();
                    break;
                }
            }
        }
        else{
            for (int i=n-1; i >= 0; i--){
                if (x[i] == -1){
                    x[i] = A;
                    var++;
                    cout << i+1 << endl;
                    cout.flush();
                    break;
                }
                if (x[i] < A){
                    x[i] = A;
                    cout << i+1 << endl;
                    cout.flush();
                    break;
                }
            }
        }
    }
    return 0;
}