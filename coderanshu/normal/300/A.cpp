#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> p,n,z;
    int q,x,i;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>x;
        if(x>0)p.push_back(x);
        else if(x<0)n.push_back(x);
        else z.push_back(x);
    }
    if(p.size()==0)
    {
        p.push_back(n[n.size()-1]);p.push_back(n[n.size()-2]);
        n.pop_back();
        n.pop_back();
    }
    x=1;
    
    if(n.size()%2==0)
    {
        z.push_back(n[n.size()-1]);n.pop_back();
    }
    cout<<n.size()<<" ";
    for(i=0;i<n.size();i++)
    cout<<n[i]<<" ";
    cout<<"\n"<<p.size()<<" ";
    for(i=0;i<p.size();i++)
    cout<<p[i]<<" ";
    cout<<"\n"<<z.size()<<" ";
    for(i=0;i<z.size();i++)
    cout<<z[i]<<" ";
    return 0;
}