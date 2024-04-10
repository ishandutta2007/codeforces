#include <iostream>
#include <algorithm>
using namespace std;
int v[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    int x=n/2;
    if(n%2)
        x++;
    nth_element(v+1,v+x,v+n+1);
    cout<<v[x];
    return 0;
}