#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool us[11];
vector <int> sp;
int que(int i, int j)
{
    cout<<"? "<<i<<" "<<j<<"\n";
    int re;
    cin>>re;
    return re;
}
int f(int i)
{
    int x=(1<<11)-1;
    for(int a=0; a<sp.size(); a+=2)
    {
        int j=sp[a];
        if(j==i) j=sp[a+1];

        x&=que(i, j);
    }
    return x;
}
main()
{
    int n, q=11;
    cin>>n;
    while(q)
    {
        int i=rnd()%n+1, j=rnd()%(n-1)+1;
        if(i==j) j=n;
        int x=que(i, j), add=0;
        for(int a=0; a<11; a++)
        {
            if(!us[a] and (x&(1<<a))==0) us[a]=1, q--, add=1;
        }
        if(add)
        {
            sp.push_back(i);
            sp.push_back(j);
        }
    }
    int i=1, x=f(1);
    for(int a=2; a<=n; a++)
    {
        if(que(i, a)==x)
        {
            i=a, x=f(a);
        }
    }
    int an[n+1];
    an[i]=0;
    for(int a=1; a<=n; a++)
    {
        if(a!=i) an[a]=que(i, a);
    }
    cout<<"!";
    for(int a=1; a<=n; a++) cout<<" "<<an[a];
    cout<<"\n";
}