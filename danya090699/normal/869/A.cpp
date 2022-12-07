#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    int ar[n], ar2[n];
    set <int> se;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], se.insert(ar[a]);
    }
    for(int a=0; a<n; a++)
    {
        cin>>ar2[a], se.insert(ar2[a]);
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(se.find(ar[a]^ar2[b])!=se.end()) q^=1;
        }
    }
    if(q) cout<<"Koyomi";
    else cout<<"Karen";
}