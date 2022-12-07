#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, cu=0, q, an=-1;
    long long k;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(x>cu)
        {
            if(cu!=0) q=1;
            else q=0;
            cu=x;
        }
        else q++;
        if(q==k)
        {
            an=cu;
            break;
        }
    }
    if(an==-1) cout<<n;
    else cout<<an;
}