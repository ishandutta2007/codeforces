#include <bits/stdc++.h>
//#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n=s.size();
    char Min='z';
    for(int i=0;i<n;i++)
    {
        if(s[i]<=Min)
        {
            Min=s[i];
            cout << "Mike\n";
        }
        else cout << "Ann\n";
    }
}