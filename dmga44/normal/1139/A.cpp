#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res=0;
    for(ll i=0;i<s.size();i++)
        if((s[i]-'0')%2==0)
            res+=(i+1);
    db(res)

    return 0;
}