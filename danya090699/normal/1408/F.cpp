#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) ar[a]=a+1;
    vector <pair <int, int> > an;
    int x=1;
    while(x*2<n) x*=2;
    for(int i=0; i<2; i++)
    {
        for(int q=2; q<=x; q*=2)
        {
            for(int a=0; a+q<=x; a+=q)
            {
                for(int b=0; b<q/2; b++) an.push_back({ar[a+b], ar[a+b+q/2]});
            }
        }
        reverse(ar, ar+n);
    }
    cout<<an.size();
    for(int a=0; a<an.size(); a++) printf("\n%d %d", an[a].first, an[a].second);
}