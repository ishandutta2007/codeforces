#include <bits/stdc++.h>
using namespace std;
void err()
{
    cout<<-1;
    exit(0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n+1];
    for(int a=1; a<=n; a++) scanf("%d", &ar[a]);
    vector <pair <int, int> > an;
    vector <int> sp1, sp2;
    for(int a=n; a; a--)
    {
        if(ar[a]==1)
        {
            an.push_back({a, a});
            sp1.push_back(a);
        }
        if(ar[a]==2)
        {
            if(sp1.size())
            {
                an.push_back({sp1.back(), a});
                sp1.pop_back();
                sp2.push_back(a);
            }
            else err();
        }
        if(ar[a]==3)
        {
            if(sp2.size())
            {
                an.push_back({a, a});
                an.push_back({a, sp2.back()});
                sp2.pop_back();
                sp2.push_back(a);
            }
            else if(sp1.size())
            {
                an.push_back({a, a});
                an.push_back({a, sp1.back()});
                sp1.pop_back();
                sp2.push_back(a);
            }
            else err();
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}