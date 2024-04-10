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
        string s;
        cin >> s;
        int n=s.size();
        for(int i=0;i<n;i+=2) s[i]=(s[i]!='a'?'a':'b');
        for(int i=1;i<n;i+=2) s[i]=(s[i]!='z'?'z':'y');
        cout << s << "\n";
    }
    return 0;
}