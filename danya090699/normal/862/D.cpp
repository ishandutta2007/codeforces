#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, v1, v2;
    cin>>n;
    cout<<"? ";
    for(int a=0; a<n; a++) cout<<0;
    cout<<"\n";
    cin>>v1;
    v1=n-v1;
    cout<<"? 1";
    for(int a=1; a<n; a++) cout<<0;
    cout<<"\n";
    cin>>v2;
    v2=n-v2;
    if(v1>v2)
    {
        int nq=v1;
        int l=0, r=n;
        while(r-l>1)
        {
            int mid=(l+r)/2, cu;
            cout<<"? ";
            for(int a=0; a<mid; a++) cout<<1;
            for(int a=mid; a<n; a++) cout<<0;
            cout<<"\n";
            cin>>cu;
            cu=n-cu;
            if(cu==nq-mid) l=mid;
            else r=mid;
        }
        cout<<"! 1 "<<r;
    }
    else
    {
        int eq=n-v1;
        int l=0, r=n;
        while(r-l>1)
        {
            int mid=(l+r)/2, cu;
            cout<<"? ";
            for(int a=0; a<mid; a++) cout<<0;
            for(int a=mid; a<n; a++) cout<<1;
            cout<<"\n";
            cin>>cu;
            cu=n-cu;
            if(cu==eq-mid) l=mid;
            else r=mid;
        }
        cout<<"! "<<r<<" 1";
    }
}