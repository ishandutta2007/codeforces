#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, k=1;
        string s;
        cin>>n>>s;
        string an=s;
        for(int a=2; a<=n; a++)
        {
            string cu=s.substr(a-1, n-a+1), r=s.substr(0, a-1);
            if((n-a+1)&1) reverse(r.begin(), r.end());
            cu+=r;
            if(cu<an) an=cu, k=a;
        }
        cout<<an<<"\n"<<k<<"\n";
    }
}