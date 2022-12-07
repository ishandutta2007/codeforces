#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    set <int> se;
    vector <int> an;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=n-1; a>=0; a--)
    {
        if(se.find(ar[a])==se.end())
        {
            an.push_back(ar[a]);
            se.insert(ar[a]);
        }
    }
    reverse(an.begin(), an.end());
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}