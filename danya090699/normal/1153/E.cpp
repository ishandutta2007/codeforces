#include <bits/stdc++.h>
using namespace std;
int que(int x1, int y1, int x2, int y2)
{
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    int re;
    cin>>re;
    return re;
}
int main()
{
    int n;
    cin>>n;
    for(int a=1; a<n; a++)
    {
        if(que(1, 1, a, n)%2)
        {
            int x[2]={a, -1}, y[2];
            for(int b=n; ; b--)
            {
                if(que(b, 1, n, n)%2)
                {
                    x[1]=b;
                    break;
                }
            }
            for(int i=0; i<2; i++)
            {
                int l=0, r=n;
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    if(que(x[i], 1, x[i], mid)%2) r=mid;
                    else l=mid;
                }
                y[i]=r;
            }
            cout<<"! "<<x[0]<<" "<<y[0]<<" "<<x[1]<<" "<<y[1]<<"\n";
            exit(0);
        }
    }
    for(int a=1; a<n; a++)
    {
        if(que(1, 1, n, a)%2)
        {
            int y[2]={a, -1}, x[2];
            for(int b=n; ; b--)
            {
                if(que(1, b, n, n)%2)
                {
                    y[1]=b;
                    break;
                }
            }
            for(int i=0; i<2; i++)
            {
                int l=0, r=n;
                while(r-l>1)
                {
                    int mid=(l+r)>>1;
                    if(que(1, y[i], mid, y[i])%2) r=mid;
                    else l=mid;
                }
                x[i]=r;
            }
            cout<<"! "<<x[0]<<" "<<y[0]<<" "<<x[1]<<" "<<y[1]<<"\n";
            exit(0);
        }
    }
}