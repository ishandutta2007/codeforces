#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, l;
        cin>>n>>l;
        vector <int> sp;
        sp.push_back(0);
        for(int a=0; a<n; a++)
        {
            int p;
            scanf("%d", &p);
            sp.push_back(p);
        }
        sp.push_back(l);

        double lg=0, rg=l;
        for(int i=0; i<60; i++)
        {
            double mid=(lg+rg)/2, su=0;
            for(int j=0; j<2; j++)
            {
                double lef=mid;
                for(int a=0; a+1<sp.size(); a++)
                {
                    double di=abs(sp[a]-sp[a+1]), t=min(lef, di/(a+1));
                    su+=t*(a+1), lef-=t;
                }
                reverse(sp.begin(), sp.end());
            }
            if(su<l) lg=mid;
            else rg=mid;
        }
        cout<<fixed<<setprecision(10)<<rg<<"\n";
    }
}