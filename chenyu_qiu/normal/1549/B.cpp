#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
bool st[N];

void solve()
{
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    for(int i = 0;i <= n;i ++) st[i] = false;

    int res = 0;
    for(int i = 0;i < n;i ++ ){
        if(i - 1 >= 0 && !st[i - 1] && a[i - 1] == '1' && b[i] == '1'){
            res ++;
            st[i - 1] = true;
        }else if(a[i] == '0' && !st[i] && b[i] == '1'){
            res ++;
            st[i] = true;
        }else if(i + 1 <= n - 1 && !st[i + 1] && a[i + 1] == '1' && b[i] == '1'){
            res ++;
            st[i + 1] = true;
        }
    }

    cout << res <<'\n';
}
int main()
{
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}