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
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        int c=0;
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            c+=ranges::count(s[i],'1');
        }
        int mn=3;
        for(int i=0;i+1<n;i++)
        {
            for(int j=0;j+1<m;j++)
            {
                int sum=0;
                for(int a=0;a<2;a++) for(int b=0;b<2;b++) sum+=(s[i+a][j+b]=='1');
                if(sum>0) mn=min(mn,max(1,sum-1));
            }
        }
        if(c>0) cout << 1+c-mn << "\n";
        else cout << "0\n";
    }
    return 0;
}