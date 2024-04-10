#include<bits/stdc++.h>
using namespace std;
#define l long
int main()
{
    l int n,i;
    cin>>n;
    pair<l int,l int> p[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    for(i=0;i<n-1;i++)
    {
        if(p[i].second>p[i+1].second)
        {
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
    return 0; 
}