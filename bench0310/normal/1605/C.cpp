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
        int res=n+1;
        for(int i=0;i<n;i++)
        {
            array<int,3> c={0,0,0};
            for(int j=0;j<min(n-i,7);j++)
            {
                c[s[i+j]-'a']++;
                if(j>0&&c[0]>max(c[1],c[2])) res=min(res,j+1);
            }
        }
        if(res==n+1) res=-1;
        cout << res << "\n";
    }
    return 0;
}