#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int q, sum;
        cin>>q>>sum;
        cout<<(sum/q)*(sum/q)*(q-sum%q)+(sum/q+1)*(sum/q+1)*(sum%q)<<"\n";
    }
}