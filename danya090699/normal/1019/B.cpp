#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if((n/2)%2) cout<<"! -1";
    else
    {
        int x, y;
        cout<<"? "<<1<<"\n";
        cin>>x;
        cout<<"? "<<1+n/2<<"\n";
        cin>>y;
        if(x==y) cout<<"! 1";
        else if(x<y)
        {
            int lg=1, rg=n/2+1;
            while(rg-lg>1)
            {
                int mid=(lg+rg)>>1, x2, y2;
                cout<<"? "<<mid<<"\n";
                cin>>x2;
                cout<<"? "<<n/2+mid<<"\n";
                cin>>y2;
                if(x2<y2) lg=mid;
                else rg=mid;
            }
            cout<<"! "<<rg;
        }
        else
        {
            int lg=1, rg=n/2+1;
            while(rg-lg>1)
            {
                int mid=(lg+rg)>>1, x2, y2;
                cout<<"? "<<mid<<"\n";
                cin>>x2;
                cout<<"? "<<n/2+mid<<"\n";
                cin>>y2;
                if(x2>y2) lg=mid;
                else rg=mid;
            }
            cout<<"! "<<rg;
        }
    }
}