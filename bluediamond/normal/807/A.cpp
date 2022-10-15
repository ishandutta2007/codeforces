#include <bits/stdc++.h>
using namespace std;
const int nmax=1000;
int n;
struct data
{
    int a,b;
};
data v[nmax+5];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i].a>>v[i].b;
    for(int i=1;i<=n;i++)
        if(v[i].a!=v[i].b)
        {
            cout<<"rated";
            return 0;
        }
    for(int i=1;i<n;i++)
    {
        if(v[i].a<v[i+1].a)
        {
            cout<<"unrated";
            return 0;
        }
    }
    cout<<"maybe";
    return 0;
}
/**

**/