#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nax=100+7;
int a[nax][nax];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                string s;
                cin>>s;
                for(int j=1;j<=n;j++)
                        if(s[j-1]=='o')
                        {
                                a[i-1][j]++;
                                a[i+1][j]++;
                                a[i][j-1]++;
                                a[i][j+1]++;
                        }
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        if(a[i][j]%2==1)
                                ok=0;
        if(ok)
                cout<<"YES\n";
        else
                cout<<"NO\n";
        return 0;
}