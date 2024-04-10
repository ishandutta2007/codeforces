#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    vector <double> ar(1, 0);
    map <pair <int, int>, vector <double> > ma;
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x!=0 or y!=0)
        {
            int k=__gcd(abs(x), abs(y));
            int vx=x/k, vy=y/k;
            if(vx==0) vy/=abs(vy);
            if(vy==0) vx/=abs(vx);
            ma[{vx, vy}].push_back(sqrt(1ll*x*x+1ll*y*y));
        }
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        vector <double> &sp=(*it).second;
        sort(sp.begin(), sp.end());
        int q=0;
        while(sp.size() and k-1-(q*2)>=0)
        {
            ar.push_back(sp.back()*(k-1-q*2));
            sp.pop_back(), q++;
        }
        double su=0;
        for(int a=0; a<sp.size(); a++)
        {
            double va=su*(-2);

            if(k-1-q*2==-1) va-=sp[a];
            else va-=sp[a]*2;

            ar.push_back(va);
            su+=sp[a];
        }
    }
    sort(ar.begin(), ar.end(), greater<double>());
    double an=0;
    for(int a=0; a<k; a++) an+=ar[a];
    cout<<fixed<<setprecision(10)<<an;
}