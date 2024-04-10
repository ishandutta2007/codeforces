#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf=2e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int p, k;
    cin>>p>>k;
    inf-=inf%k;
    vector <int> an;
    while(!(p>=0 and p<k))
    {
        int x=(p+inf)%k;
        an.push_back(x);
        p=(x-p)/k;
    }
    cout<<an.size()+1<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
    cout<<p;
}