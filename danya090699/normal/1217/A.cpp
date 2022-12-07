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
        int str, in, exp, an=0;
        cin>>str>>in>>exp;
        if(str<=in) exp-=in+1-str, str=in+1;
        if(exp>=0) an=min(exp, str-1-in), exp-=an;
        if(exp>=0) an+=exp/2+1;
        cout<<an<<"\n";
    }
}