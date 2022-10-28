#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int func( pair<int,int> a,pair<int,int> b)
{
    return a.s<=b.s;
}
int main()
{
    int n,i,j,count=0;
    bool xl,xr,yl,yr;
    cin>>n;
    int a[n][2];
    for(i-0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    for(i=0;i<n;i++)
    {
        xr=xl=yr=yl=false;
        for(j=0;j<n;j++)
        {
            if(a[i][0]==a[j][0] && a[i][1]<a[j][1])yr=true;
            else if(a[i][0]==a[j][0] && a[i][1]>a[j][1])yl=true;
            else if(a[i][1]==a[j][1] && a[i][0]<a[j][0])xr=true;
            else if(a[i][1]==a[j][1] && a[i][0]>a[j][0])xl=true;
        }
        if(xl && yl && xr && yr)
        {
            count++;
        }
    }
    cout<<count;
    return 0; 
}