#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
string a;
int v[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a;
    for(int i=1;i<=n;i++)
        v[i]=a[i-1];
    for(int i=1;i<=n;i++)
        if(n%i==0)
        {
            reverse(v+1,v+i+1);
        }
    for(int i=1;i<=n;i++)
        cout<<char(v[i]);
    cout<<"\n";
    return 0;
}
/**

**/