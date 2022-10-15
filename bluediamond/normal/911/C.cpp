#include <bits/stdc++.h>
using namespace std;
int k1,k2,k3,lim=10,x=100;
bool ap[1005];
int main()
{
    cin>>k1>>k2>>k3;
    for(int i1=1;i1<=lim;i1++)
    for(int i2=1;i2<=lim;i2++)
    for(int i3=1;i3<=lim;i3++)
    {
        for(int j=0;i1+k1*j<=100;j++) ap[i1+k1*j]=1;
        for(int j=0;i2+k2*j<=100;j++) ap[i2+k2*j]=1;
        for(int j=0;i3+k3*j<=100;j++) ap[i3+k3*j]=1;
        bool ok=1;
        int val=max(i1,max(i2,i3));
        for(int j=val;j<=100;j++)
            if(ap[j]==0)
            {
                ok=0;
                break;
            }
        if(ok==1)
        {
            cout<<"YES";
            return 0;
        }
        for(int j=0;j<=100;j++)
            ap[j]=0;
    }
    cout<<"NO";
    return 0;
}
/**
**/