#include <bits/stdc++.h>
using namespace std;
bool prime(int x)
{
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0) return false;
    }
    return true;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=1;
    cin>>n;
    vector <pair <int, int> > an;
    for(int a=0; a<n; a++) an.push_back({a+1, (a+1)%n+1});
    while(!prime(an.size()))
    {
        an.push_back({yk, yk+n/2}), yk++;
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}