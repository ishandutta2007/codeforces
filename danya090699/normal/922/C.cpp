#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, k, fo=0;
    cin>>n>>k;
    set <int> os;
    for(int a=1; a<=k; a++)
    {
        if(os.find(n%a)!=os.end())
        {
            fo=1;
            break;
        }
        else os.insert(n%a);
    }
    if(fo) cout<<"No";
    else cout<<"Yes";
}