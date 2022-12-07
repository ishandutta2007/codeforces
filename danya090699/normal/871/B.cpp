#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q=0;
    cin>>n;
    int xo[n], xo2[n], an[n];
    for(int a=0; a<n; a++)
    {
        cout<<"? "<<a<<" "<<0<<"\n";
        cin>>xo[a];
    }
    for(int a=0; a<n; a++)
    {
        cout<<"? "<<0<<" "<<a<<"\n";
        cin>>xo2[a];
    }
    for(int a=0; a<n; a++)
    {
        int p[n], ar[n], ok=1;
        for(int b=0; b<n; b++)
        {
            p[b]=a^xo[b];
            ar[p[b]]=b;
        }
        for(int b=0; b<n; b++)
        {
            if((p[0]^ar[b])!=xo2[b]) ok=0;
        }
        if(ok)
        {
            q++;
            for(int b=0; b<n; b++) an[b]=p[b];
        }
    }
    cout<<"!\n"<<q<<"\n";
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}