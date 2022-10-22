#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string t, a, b, c;
int pos[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    int n=t.size();

    cout << "? ";
    for(int i=0;i<n;i++)
        cout << char(i/(26*26)+'a');
    cout << endl;
    cin >> a;

    cout << "? ";
    for(int i=0;i<n;i++)
        cout << char(i/26%26+'a');
    cout << endl;
    cin >> b;

    cout << "? ";
    for(int i=0;i<n;i++)
        cout << char(i%26+'a');
    cout << endl;
    cin >> c;

    cout << "! ";

    for(int i=0;i<n;i++)
        pos[(a[i]-'a')*26*26+(b[i]-'a')*26+(c[i]-'a')]=i;
    for(int i=0;i<n;i++)
        cout << t[pos[i]];
    cout << endl;
}