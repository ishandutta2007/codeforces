#include <bits/stdc++.h>
#define int unsigned int
using namespace std;
const int sz=1e8;
bitset <sz> er;
int n, A, B, C, D, an=0;
int add(int x)
{
    int va=A*x*x*x+B*x*x+C*x+D, q=n/x, su=0;
    while(q)
    {
        su+=q, q/=x;
    }
    an+=va*su;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>A>>B>>C>>D;
    int lg=1;
    while(lg*lg<=n) lg++;
    vector <int> pri;
    for(int a=2; a<lg; a++)
    {
        if(er[a]==0)
        {
            pri.push_back(a), add(a);
            for(int b=a+a; b<lg; b+=a) er[b]=1;
        }
    }
    while(lg<=n)
    {
        int rg=min(lg+sz, n+1);
        er.reset();
        for(int a=0; a<pri.size(); a++)
        {
            int x=pri[a];
            int st=x*(lg/x);
            if(st<lg) st+=x;
            for(st; st<rg; st+=x) er[st-lg]=1;
        }
        for(int a=lg; a<rg; a++) if(er[a-lg]==0) add(a);
        lg=rg;
    }
    cout<<an;
}