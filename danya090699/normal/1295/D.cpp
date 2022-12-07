#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T)
    {
        T--;
        int a, m;
        cin>>a>>m;
        int d=__gcd(a, m);
        a/=d, m/=d;
        int l=a-1, r=a+m-1;
        vector <int> de;
        int t=m;
        for(int b=2; b*b<=t; b++)
        {
            if(t%b==0)
            {
                de.push_back(b);
                while(t%b==0) t/=b;
            }
        }
        if(t>1) de.push_back(t);

        int an=0;
        for(int mask=0; mask<(1<<de.size()); mask++)
        {
            int cu=1;
            for(int i=0; i<de.size(); i++) if(mask&(1<<i)) cu*=de[i];

            if(__builtin_popcountll(mask)%2==0) an+=r/cu-l/cu;
            else an-=r/cu-l/cu;
        }

        cout<<an<<"\n";
    }
}