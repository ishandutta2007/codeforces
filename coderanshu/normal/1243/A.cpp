#include<bits/stdc++.h>
using namespace std;
// if if concept

int main()
{
    int a[1000];
    int k,i,n,j;
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
        }
        sort(a,a+n,greater<int>());
        j=0;
        while(a[j]>=j+1 && j<n)
        {
            j++;
        }
        cout<<min(a[j-1],j)<<"\n";
    }
    return 0;
}