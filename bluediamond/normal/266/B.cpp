#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,q;
string s[55];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    cin>>s[0];
    for(int i=1;i<=q;i++)
    {
        s[i]=s[i-1];
        for(int j=0;j+1<n;j++)
        {
            if(s[i-1][j]=='B' & s[i-1][j+1]=='G')
            {
                swap(s[i][j],s[i][j+1]);
            }
        }
    }
    cout<<s[q]<<"\n";
    return 0;
}
/**


**/