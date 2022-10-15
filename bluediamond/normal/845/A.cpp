#include <iostream>
#include <algorithm>
using namespace std;
int v[205];
int main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=2*n;i++)
        cin>>v[i];
    sort(v+1,v+2*n+1);
    if(v[n]==v[n+1])
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}