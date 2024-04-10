#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s,t;
        cin >> s >> t;
        char a=s.back();
        char b=t.back();
        string ord="SML";
        if(s==t) cout << "=";
        else if(ord.find(a)!=ord.find(b)) cout << "<>"[ord.find(a)>ord.find(b)];
        else
        {
            int l=s.size(),r=t.size();
            cout << "<>"[(l<r)^(a=='L')];
        }
        cout << "\n";
    }
    return 0;
}