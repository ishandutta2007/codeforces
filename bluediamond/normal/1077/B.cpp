#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int Disturb = 0;
    for(int i = 1; i + 1 < n; i++)
        if(a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
            Disturb++, a[i + 1] = 0;
    cout << Disturb << "\n";
}
/**

**/