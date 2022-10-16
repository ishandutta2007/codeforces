#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool ok = 1;
    for(int i = 0; i + 1 < n; i++){
        if(abs(a[i] - a[i+1]) >= 2)
            ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
}