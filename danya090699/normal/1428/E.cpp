#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int x, int q)
{
    int q2=x%q, q1=q-q2;
    return (x/q)*(x/q)*q1+(x/q+1)*(x/q+1)*q2;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], q[n], an=0;
    set <pair <int, int>, greater <pair <int, int> > > se;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        q[a]=1;
        an+=ar[a]*ar[a];
        if(ar[a]>q[a]) se.insert({f(ar[a], 1)-f(ar[a], 2), a});
    }
    for(int a=0; a<k-n; a++)
    {
        int i=(*se.begin()).second;
        an-=(*se.begin()).first;
        se.erase(se.begin());
        q[i]++;
        if(ar[i]>q[i]) se.insert({f(ar[i], q[i])-f(ar[i], q[i]+1), i});
    }
    cout<<an;
}