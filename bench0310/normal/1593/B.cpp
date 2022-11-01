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
        string n;
        cin >> n;
        vector<bool> v(10,0);
        int m=n.size();
        vector<string> opt={"00","25","50","75"};
        for(int i=m-1;i>=0;i--)
        {
            bool ok=0;
            for(string a:opt) ok|=(n[i]==a[0]&&v[a[1]-'0']);
            if(ok)
            {
                cout << m-i-2 << "\n";
                break;
            }
            v[n[i]-'0']=1;
        }
    }
    return 0;
}