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
        vector<int> l(n,0);
        l[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1]) l[i]=l[i-1]+1;
            else l[i]=1;
        }
        vector<int> r(n,0);
        r[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]!=s[i+1]) r[i]=r[i+1]+1;
            else r[i]=1;
        }
        for(int i=0;i<=n;i++)
        {
            int res=1;
            if(i>0&&s[i-1]=='L') res+=l[i-1];
            if(i<n&&s[i]=='R') res+=r[i];
            cout << res << " \n"[i==n+1];
        }
    }
    return 0;
}