#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int b[128], k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n=s.size();

    if(n<=3)
    {
        cout << "No";
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        b[s[i]]++;
        if(b[s[i]]==1)
            k++;
    }
    if(k!=2 && k!=3 && k!=4)
    {
        cout << "No";
        return 0;
    }
    if(k!=2)
    {
        cout << "Yes";
        return 0;
    }

    for(int i=0;i<128;i++)
        if(b[i]==1)
    {
        cout << "No";
        return 0;
    }

    cout << "Yes";
}