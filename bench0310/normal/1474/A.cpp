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
        string b;
        cin >> n >> b;
        int prv=-1;
        string a(n,'$');
        for(int i=0;i<n;i++)
        {
            if((b[i]-'0')+1!=prv) a[i]='1';
            else a[i]='0';
            prv=(a[i]-'0'+b[i]-'0');
        }
        cout << a << "\n";
    }
    return 0;
}