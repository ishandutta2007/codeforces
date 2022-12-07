#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, x=1;
        cin>>n;
        if(n==2) cout<<1<<"\n"<<0<<"\n";
        else if(n==3) cout<<1<<"\n"<<1<<"\n";
        else
        {
            vector <int> an;
            n--;
            while(1)
            {
                if(n<=6*x)
                {
                    if(n<=4*x)
                    {
                        an.push_back((n-2*x)/2);
                        an.push_back(n&1);
                    }
                    else
                    {
                        an.push_back(x);
                        an.push_back(n-4*x);
                    }
                    break;
                }
                else
                {
                    an.push_back(x), x*=2, n-=x;
                }
            }
            cout<<an.size()<<"\n";
            for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
            cout<<"\n";
        }
    }
}