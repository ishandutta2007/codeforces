#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    //freopen("1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int mn = 1e9;
    for (int i=0; i < n; i++) mn = min(mn, v[i]);
    int a=0, b=0, c=0;
    for (int i=0; i < n; i++){
        if (v[i] == mn) a++;
        if (v[i] == mn+1) b++;
        if (v[i] == mn+2) c++;
    }
    if (c==0){
        cout << n << endl;
        for (int i=0; i < n; i++) cout << v[i] << " ";
        return 0;
    }
    int A = min(a, c);
    int B = b/2;
    if (A > B){
        cout << n-2*A << endl;
        for (int i=0; i < a-A;i++) cout << mn << " ";
        for (int i=0; i < b+2*A; i++) cout << mn+1 << " ";
        for (int i=0; i < c-A; i++) cout << mn+2 << " ";
    }
    else{
        cout << n-2*B << endl;
        for (int i=0; i < a+B;i++) cout << mn << " ";
        for (int i=0; i < b%2; i++) cout << mn+1 << " ";
        for (int i=0; i < c+B; i++) cout << mn+2 << " ";
    }
    return 0;
}