#include <bits/stdc++.h>

using namespace std;

int n,a,b;

int main()
{
    cin>>n>>a>>b;
    if(a>b)
        swap(a,b);
    if(a<=n/2 && b>n/2)
    {
        cout<<"Final!";
        return 0;
    }
    int g=log2(n);
    while(g>=0)
    {
        int l=(1<<g);
        int st,dr;
        bool ok=0;
        st=1;
        while(1)
        {
            dr=st+l-1;
            if(st<=a && a<=dr)
            {
                if(st<=b && b<=dr)
                    ok=1;
                else
                    ok=0;
                break;
            }
            st+=l;
        }
        if(!ok)
        {
            cout<<g+1;
            return 0;
        }
        g--;
    }
    return 0;
}
/**
1 2  3 4    5 6  7 8
* *  * *    * *  * *
**/