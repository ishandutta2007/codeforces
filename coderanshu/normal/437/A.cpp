#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    pair<int,int> p[4];
    char a[4][102];
    for(i=0;i<4;i++)
    {
       cin>>a[i];
       p[i].first=strlen(a[i])-2;
       p[i].second=i;
    }
    sort(p,p+4);
    if(p[3].first>=2*p[2].first && p[0].first*2<=p[1].first)
    cout<<"C";
    else if(p[3].first>=2*p[2].first)
    cout<<a[p[3].second][0];
    else if(p[0].first*2<=p[1].first)
    cout<<a[p[0].second][0];
    else cout<<"C";
    return 0;
}