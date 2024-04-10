#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool e[105][105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
                cin>>s;
            for(int j=1;j<=m;j++)
        {
            e[i][j]=(s[j-1]=='-');
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(e[i][j])
            {
                cout<<"-";
            }
            else
            {
                int x=(i+j)%2;
                if(x==0)
                {
                    cout<<"W";
                }
                else
                {
                    cout<<"B";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
/**

**/