#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s,st;
        cin >> s >> st;
        auto cmp=[&](char a,char b)->bool
        {
            if(a=='b'||a=='c') a^=('b'^'c');
            if(b=='b'||b=='c') b^=('b'^'c');
            return (a<b);
        };
        ranges::sort(s);
        if(st=="abc"&&s[0]=='a') ranges::sort(s,cmp);
        cout << s << "\n";
    }
    return 0;
}