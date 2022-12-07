#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, c;
    cin>>n>>m>>c;
    int ar[n], l=0, r=n-1;
    while(l<=r)
    {
        int x, p;
        cin>>x;
        if(x<=c/2)
        {
            p=l;
            for(int a=0; a<l; a++)
            {
                if(ar[a]>x)
                {
                    p=a;
                    break;
                }
            }
            if(p==l) l++;
        }
        else
        {
            p=r;
            for(int a=n-1; a>r; a--)
            {
                if(ar[a]<x)
                {
                    p=a;
                    break;
                }
            }
            if(p==r) r--;
        }
        ar[p]=x;
        cout<<p+1<<"\n";
    }
}