#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],b=0,c[n],m=0,p=0,t;
    multiset<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        while(*(s.rbegin())-*(s.begin())>k)s.erase(s.find(a[b++]));
        t=i-b+1;
        if(t==m)c[p++]=b;
        else if(t>m)m=t,c[0]=b,p=1;
    }
    cout<<m<<" "<<p<<"\n";
    for(int i=0;i<p;i++) cout<<c[i]+1<<" "<<c[i]+m<<"\n";
    return 0;
}