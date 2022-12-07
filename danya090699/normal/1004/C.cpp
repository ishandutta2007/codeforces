#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], q[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    set <int> se;
    for(int a=n-1; a>=0; a--)
    {
        q[a]=se.size();
        se.insert(ar[a]);
    }
    se.clear();
    long long an=0;
    for(int a=0; a<n; a++)
    {
        if(se.find(ar[a])==se.end())
        {
            an+=q[a];
            se.insert(ar[a]);
        }
    }
    cout<<an;
}