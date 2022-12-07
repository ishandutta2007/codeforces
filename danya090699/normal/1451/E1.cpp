#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    int va[n];
    va[0]=0;
    for(int a=1; a<n; a++)
    {
        cout<<"XOR "<<a<<" "<<a+1<<endl;
        int x;
        cin>>x;
        va[a]=va[a-1]^x;
    }
    int p[n];
    for(int a=0; a<n; a++) p[a]=-1;
    for(int a=0; a<n; a++)
    {
        if(p[va[a]]==-1) p[va[a]]=a;
        else
        {
            cout<<"AND "<<p[va[a]]+1<<" "<<a+1<<endl;
            int x;
            cin>>x;
            x^=va[a];
            cout<<"!";
            for(int b=0; b<n; b++) cout<<" "<<(va[b]^x);
            cout<<endl;
            return 0;
        }
    }
    cout<<"AND "<<p[0]+1<<" "<<p[1]+1<<endl;
    int x;
    cin>>x;
    cout<<"AND "<<p[0]+1<<" "<<p[2]+1<<endl;
    int y;
    cin>>y;
    if(y&1) x++;

    cout<<"!";
    for(int a=0; a<n; a++) cout<<" "<<(va[a]^x);
    cout<<endl;
}