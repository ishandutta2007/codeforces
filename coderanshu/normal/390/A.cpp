#include<bits/stdc++.h>
using namespace std;
// if if concept
int main()
{
    long int n,x,y,i;
    cin>>n;
    set<int> ys;
    set<int> xs;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        xs.insert(x);
        ys.insert(y);
    }
    cout<<min(xs.size(),ys.size());
    return 0;
}