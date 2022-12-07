#include <bits/stdc++.h>
using namespace std;
int de(int x, int y)
{
    return x/y+(x%y>0);
}
int f(int n, int k)
{
    return n-de(n, k)-(k-1);
}
main()
{
    int n, q=0;
    cin>>n;
    int us[n];
    for(int a=0; a<n; a++) us[a]=0;
    int k=1;
    for(int a=2; a<=n; a++) if(f(n, k)<f(n, a)) k=a;
    while(q<f(n, k))
    {
        vector <int> sp;
        for(int a=0; a+1<n; a++)
        {
            if(a%k!=k-1 and !us[a]) us[a]=1, sp.push_back(a+1);
            if(sp.size()==k) break;
        }
        q+=k;
        cout<<k;
        for(int a=0; a<k; a++) cout<<" "<<sp[a];
        cout<<"\n";
        int x;
        cin>>x;
        x--;
        for(int a=0; a<k; a++)
        {
            if(us[x]) us[x]=0, q--;
            x=(x+1)%n;
        }
    }
    cout<<0<<"\n";
}