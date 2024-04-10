#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;

bool gl(char c)
{
    return (c=='a' || c=='o' || c=='e' || c=='u' || c=='y' || c=='i' || c=='1');
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for(int i=1; i<n; i++)
        if(gl(s[i]) && gl(s[i-1]))
            s[i]='1';

    for(int i=0; i<n; i++)
        if(s[i]!='1')
            cout << s[i];
}