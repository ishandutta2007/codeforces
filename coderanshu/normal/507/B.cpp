#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(0);
    long int r,x1,y1,x2,y2;
    double d;
    cin>>r>>x1>>y1>>x2>>y2;
    d=sqrt(pow(x2-x1,2)+pow(y2-y1,2))/(2*r);
    long int temp=d;
    (temp==d)?cout<<temp:cout<<temp+1;
    
    return 0;
}