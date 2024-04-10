#include <iostream>
using namespace std;
int v[105];
int main()
{
    int n,i,p1,p2;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(p1=1;p1<=n;p1++)
        if(v[p1]>=v[p1+1])
            break;
    for(p2=p1;p2<=n;p2++)
        if(v[p2]!=v[p1])
            break;
    for(i=p2-1;i<n;i++)
        if(v[i]<=v[i+1])
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}