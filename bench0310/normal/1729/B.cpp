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
        int n;
        cin >> n;
        string a;
        cin >> a;
        string s;
        int p=n-1;
        while(p>=0)
        {
            if(a[p]!='0')
            {
                s+=char('a'+a[p]-'0'-1);
                p--;
            }
            else
            {
                s+=char('a'+stoi(a.substr(p-2,2))-1);
                p-=3;
            }
        }
        ranges::reverse(s);
        cout << s << "\n";
    }
    return 0;
}