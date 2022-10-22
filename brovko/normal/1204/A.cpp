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

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> s;
    int n=(int)s.size();
    int k=0;
    for(int i=1;i<n;i++)
        if(s[i]=='1')
        k++;
    if(k==0)
        cout << n/2;
    else cout << (n+1)/2;
}