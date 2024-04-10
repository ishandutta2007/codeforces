#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    li i,x,y,n,f;
    cin>>t;
    set<li> s;
    vector<li> v;
    while(t--)
    {
        s.clear();
        v.clear();
        cin>>n;
        for(i=0;i<n;i++)s.insert(i+1);
        f=1;
        cin>>x;
        v.push_back(x);
        y=x;
        s.erase(s.find(x));
        for(i=1;i<n;i++)
        {
            cin>>x;
            if(x==y && *s.begin()<x)
            {
                v.push_back(*s.begin());
                s.erase(s.begin());
            }
            else if(x==y && *s.begin()>=x)
            {
                f=0;
            }
            else 
            {
                v.push_back(x);
                s.erase(s.find(x));
            }
            y=x;
        }
            
        if(f)
        {
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        }
        else cout<<-1;
        cout<<"\n";
    }
    
    return 0;
}