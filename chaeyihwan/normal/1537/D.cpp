#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int m = n;
        int cnt = 0;
        while(m%2 == 0) { m /= 2; cnt++; }

        if(n == 1) cout << "Bob\n";
        else if(m == 1 && cnt%2) cout << "Bob\n";
        else if(m == 1) cout << "Alice\n";
        else if(n%2) cout << "Bob\n";
        else cout << "Alice\n";
    }
}