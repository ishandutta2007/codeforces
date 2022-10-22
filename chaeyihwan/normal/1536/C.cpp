#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v[500002];

int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'D') v[i] = 1;
            else v[i] = 0;
        }

        for(int i=1;i<n;i++) v[i] += v[i-1];
        map<pair<int, int>, int> m;
        for(int i=0;i<n;i++)
        {
            int a = i+1, b = v[i];
            int g = gcd(a, b);

            cout << ++m[{a/g, b/g}] << " ";
        }
        cout << "\n";
    }
}