#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int x[4];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        for(int i=0;i<4;i++)
        {
                cin>>x[i];
        }
        sort(x,x+4);
        for(int i=0;i<=2;i++)
        {
                cout<<x[3]-x[i]<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

**/