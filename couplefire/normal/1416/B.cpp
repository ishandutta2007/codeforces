#include <bits/stdc++.h>
using namespace std;

struct op{
    int i, j, x;
    op(){}
    op(int ii, int jj, int xx){i = ii, j = jj, x = xx;}
};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        int sum = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i+1];
            sum += arr[i+1];
        }
        if(sum%n != 0){
            cout << -1 << endl;
            continue;
        }
        sum /= n;
        vector<op> ops;
        for(int i = 2; i<=n; i++){
            if(arr[i]%i != 0){
                ops.push_back({1, i, i*(arr[i]/i+1)-arr[i]});
                ops.push_back({i, 1, (arr[i]/i+1)});
                arr[1] += i*(arr[i]/i+1);
                arr[i] = 0;
            }
            else{
                ops.push_back({i, 1, arr[i]/i});
                arr[1] += arr[i];
                arr[i] = 0;
            }
        }
        for(int i = 2; i<=n; i++){
            ops.push_back({1, i, sum});
        }
        cout << ops.size() << endl;
        for(auto p : ops){
            cout << p.i << " " << p.j << " " << p.x << endl;
        }
    }
}