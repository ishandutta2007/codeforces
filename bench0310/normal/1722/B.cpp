#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        for(char &c:a) if(c=='G') c='B';
        for(char &c:b) if(c=='G') c='B';
        if(a==b) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}