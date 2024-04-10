#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,l=0,r=0,oe=0,ee=0,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        l+=x;r+=y;
        if((x^y)%2==0)ee=1;
        else if((x&y)%2==0)oe=1;
    }
    if(l%2==0 && r%2==0 && ee)
    cout<<0;
    else if(l%2!=0 && r%2!=0 && oe)
    cout<<1;
    else cout<<-1;
    
    return 0;
}