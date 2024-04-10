#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 26

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    char c;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        a[c-'a']++;
    }

    int res=0;
    for(int i=0;i<26;i++)
        if(a[i]>1 || a[i]==n)
            res=1;
    cout << ((res) ? "Yes" : "No") << '\n';

    return 0;
}