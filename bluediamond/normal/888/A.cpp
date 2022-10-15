#include <iostream>
using namespace std;
int v[1005],n,s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=2;i<n;i++)
    {
        if(v[i-1]<v[i] and v[i]>v[i+1])s++;
        if(v[i-1]>v[i] and v[i]<v[i+1])s++;
    }
    cout<<s;
    return 0;
}