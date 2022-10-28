#include<bits/stdc++.h>
using namespace std;
int x[6];
int right()
{
    int a=(x[2]-x[0])*(x[2]-x[0]) + (x[3]-x[1])*(x[3]-x[1]);
    int b=(x[2]-x[4])*(x[2]-x[4]) + (x[3]-x[5])*(x[3]-x[5]);
    int c=(x[0]-x[4])*(x[0]-x[4]) + (x[1]-x[5])*(x[1]-x[5]);
    return (2*max(a,max(b,c))==a+b+c)&&(!(a==b) || !(b==c))&&a&&b&&c;
}
int main()
{
    int i;
    for(i=0;i<6;i++)
    cin>>x[i];
    if(right()){cout<<"RIGHT"; return 0;}
    else
    {
            for(i=0;i<6;i++)
            {
                x[i]--;
                if(right())
                {
                    cout<<"ALMOST";return 0;
                }
                else x[i]+=2;
                if(right())
                {
                    cout<<"ALMOST";return 0;
                }
                else x[i]--;
                
                
            }
    }
    cout<<"NEITHER";
    return 0;
}