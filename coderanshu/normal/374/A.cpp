#include<bits/stdc++.h>
using namespace std;
// if if concept
int main()
{
    int n,m,i,j,a,b,x,y,z=-1;
    cin>>n>>m>>i>>j>>a>>b;
    if((n-i)%a==0 && (m-j)%b==0)
    {
        x=(n-i)/a;y=(m-j)/b;
        if(((x+y-2*min(x,y))%2==0&&n>a&&m>b) || (x==0 && y==0))

        {
            if(z==-1)z=max(x,y);
            else z=min(z,max(x,y));
        }
    }
    if((n-i)%a==0 && (j-1)%b==0)
    {
        x=(n-i)/a;y=(j-1/b);
        if(((x+y-2*min(x,y))%2==0&&n>a&&m>b) || (x==0 && y==0))
       
        {
             if(z==-1)z=max(x,y);
            else z=min(z,max(x,y));
        }
    }
    if((i-1)%a==0 && (j-1)%b==0)
    {
        x=(i-1)/a;y=(j-1)/b;
         if(((x+y-2*min(x,y))%2==0&&n>a&&m>b) || (x==0 && y==0))
        {
             if(z==-1)z=max(x,y);
            else z=min(z,max(x,y));
        }
        
    }
    if((i-1)%a==0 && (m-j)%b==0)
    {
        x=(i-1)/a;y=(m-j)/b;
        if(((x+y-2*min(x,y))%2==0&&n>a&&m>b) || (x==0 && y==0))

        {
             if(z==-1)z=max(x,y);
            else z=min(z,max(x,y));
        }
    }
    if(z!=-1)cout<<z;
    else cout<<"Poor Inna and pony!";
    return 0;
}