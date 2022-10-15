#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
bool ap[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=2;i++)
    {
        int a;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            int x;
            cin>>x;
            ap[x]=1;
        }
    }
    for(int i=1;i<=n;i++)
        if(ap[i]==0)
        {
            cout<<"Oh, my keyboard!\n";
            return 0;
        }
    cout<<"I become the guy.\n";
    return 0;
}
/**

**/