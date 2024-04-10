#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin>>x>>y;
    if(y==0) cout<<"No";
    else
    {
        int q=y-1;
        if(q>x) cout<<"No";
        else
        {
            if(q==0 and x>0) cout<<"No";
            else
            {
                if((x-q)%2==0) cout<<"Yes";
                else cout<<"No";
            }
        }
    }
}