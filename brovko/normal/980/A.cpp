#include <bits/stdc++.h>
#define int long long
#define y1 iowfhjeofie
#define id long double

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n=s.size();

    int kn=0;
    int kb=0;
    for(int i=0;i<n;i++)
        if(s[i]=='-')
            kn++;
        else kb++;
    if(kn==0 || kb==0 || kn%kb==0)
        cout << "YES";
    else cout << "NO";
}