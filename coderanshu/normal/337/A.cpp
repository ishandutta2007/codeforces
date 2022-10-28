#include <iostream>
#include<vector>

using namespace std;

int main()
{
    int a[50],i,n,m,j,temp,an;
    cin>>n>>m;;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];

    }

    for(i=1;i<m;i++)
    {
       for(j=0;j<m-i;j++)
       {
           if(a[j]>a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
    }
    an=a[n-1]-a[0];
    for(i=1;i<m-n+1;i++)
    {
        an=min(an,a[i+n-1]-a[i]);
    }
    cout<<an;
    return 0;
}