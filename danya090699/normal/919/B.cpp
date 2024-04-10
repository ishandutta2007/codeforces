#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    for(int a=1; ; a++)
    {
        int su=0, x=a;
        while(x)
        {
            su+=x%10, x/=10;
        }
        if(su==10) k--;
        if(k==0)
        {
            cout<<a;
            break;
        }
    }
}