#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    for(int i=0;i<n;i++)
        if(s[i]=='n')
            cout << "1 ";
    for(int i=0;i<n;i++)
        if(s[i]=='z')
            cout << "0 ";
}