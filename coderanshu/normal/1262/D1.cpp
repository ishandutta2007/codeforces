#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
bool compare(pair<li ,int> p1,pair<li ,int> p2)
{
    if(p1.first==p2.first)
    return p1.second>p2.second;
    else 
    return p1.first<p2.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
   
    li i,m,n,k,pos,z;
    cin>>n;
     pair<li ,int> p[n];
     map<int ,li> ma;
     map<int ,li>:: iterator it;
    for(i=0;i<n;i++)
    {
        cin>>p[i].first;
        p[i].second=i;
    }
    sort(p,p+n,compare);
    cin>>m;
    while(m--)
    {
        ma.clear();
        cin>>k>>pos;
        for(i=n-1;i>=n-k;i--)
        ma.insert(make_pair(p[i].second,p[i].first));
        it=ma.begin();
        for(z=0;z<pos-1;z++,it++);
        cout<<it->second<<"\n";
    }
    return 0;
}