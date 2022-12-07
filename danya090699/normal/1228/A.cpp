#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int l, r;
    cin>>l>>r;
    for(int a=l; a<=r; a++)
    {
        set <int> se;
        int q=0, x=a;
        while(x)
        {
            se.insert(x%10), q++, x/=10;
        }
        if(q==se.size())
        {
            cout<<a;
            return 0;
        }
    }
    cout<<-1;
}