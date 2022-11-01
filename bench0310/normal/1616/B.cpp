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
        string s;
        cin >> s;
        string res(2,s[0]);
        auto f=[&](int i)
        {
            string tmp=s.substr(0,i+1);
            for(int j=i;j>=0;j--) tmp+=s[j];
            res=min(res,tmp);
        };
        f(n-1);
        for(int i=0;i+1<n;i++)
        {
            if(s[i]<s[i+1])
            {
                f(i);
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}