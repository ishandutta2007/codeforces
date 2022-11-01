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
        int l=0,r=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') l=i;
            if(s[i]==')') r=i;
        }
        if(l!=n-1&&r!=0&&((n%2)==0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}