#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x, st=1;
        cin>>x;
        while(x>=st) st*=2;
        if(x==st-1)
        {
            bool fo=0;
            for(int a=2; a*a<=x; a++)
            {
                if(x%a==0)
                {
                    cout<<x/a<<"\n";
                    fo=1;
                    break;
                }
            }
            if(fo==0) cout<<"1\n";
        }
        else cout<<st-1<<"\n";
    }
}