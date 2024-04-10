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
        int a=n/3,b=n/3;
        if((n%3)==1) a++;
        else if((n%3)==2) b++;
        cout << a << " " << b << "\n";
    }
    return 0;
}