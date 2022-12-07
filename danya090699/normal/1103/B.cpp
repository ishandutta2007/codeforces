#include <bits/stdc++.h>
using namespace std;
int que(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<"\n";
    char sy;
    cin>>sy;
    if(sy=='x') return 0;//x>=y
    else return 1;
}
int main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(s=="mistake" or s=="end") break;

        int x=1;
        while(1)
        {
            if(que(x, x*2)) x*=2;
            else break;
        }
        int l=x, r=x*2;
        if(l==1)
        {
            if(que(0, 1)) cout<<"! 2\n";
            else cout<<"! 1\n";
        }
        else
        {
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(que(l, mid)) l=mid;
                else r=mid;
            }
            cout<<"! "<<r<<"\n";
        }
    }
}