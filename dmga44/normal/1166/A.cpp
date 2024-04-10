#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int f[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        f[s[0]-'a']++;
    }

    int res=0;
    for(int i=0;i<26;i++)
    {
        int x=f[i]/2;
        int y=f[i]-x;
        res+=(x*(x-1))/2;
        res+=(y*(y-1))/2;
    }
    db(res)

    return 0;
}