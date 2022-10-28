#include<iostream>
using namespace std;
bool sort_f(int b[],int x,int y)
{
    for(int i=x+1;i<=y;i++)
    {
        if(b[i]<b[i-1])
            return false;
    }
    return true;
}
int calculate(int a[],int s,int e)
{
    if((e-s+1)==1)
        return 1;
    else if(sort_f(a,s,e))
        return e-s+1;
    else
        return max(calculate(a,s,s+(e-s)/2),calculate(a,s+(e-s+1)/2,e));
}
int main()
{
    int a[16];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<calculate(a,0,n-1);

    return 0;
}