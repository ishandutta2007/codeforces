#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<int> v;
    for(char c:s) v.push_back(c-'A'+1);
    bool ok=1;
    for(int i=2;i<(int)v.size();i++)
    {
        int a=v[i-2];
        int b=v[i-1];
        int c=v[i];
        int x=(a+b-1)%26;
        if(x==0) x=26;
        ok&=(c==x);
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}