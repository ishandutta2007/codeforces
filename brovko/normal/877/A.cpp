#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(i <= n - 5 && s.substr(i, 5) == "Danil")
            k++;

        if(i <= n - 4 && s.substr(i, 4) == "Olya")
            k++;

        if(i <= n - 5 && s.substr(i, 5) == "Slava")
            k++;

        if(i <= n - 3 && s.substr(i, 3) == "Ann")
            k++;

        if(i <= n - 6 && s.substr(i, 6) == "Nikita")
            k++;
    }

    if(k == 1)
        cout << "YES";
    else cout << "NO";
}