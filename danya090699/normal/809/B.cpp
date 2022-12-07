#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, x, y=-1;
    cin>>n>>k;
    int l=0, r=n-1;
    while(r-l>0)
    {
        int mid=(l+r)/2;
        cout<<"1 "<<mid+1<<" "<<mid+2<<"\n";
        string an;
        cin>>an;
        if(an=="TAK") r=mid;
        else l=mid+1;
    }
    x=l;
    if(x!=0)
    {
        l=0, r=x-1;
        while(r-l>0)
        {
            int mid=(l+r)/2;
            cout<<"1 "<<mid+1<<" "<<mid+2<<"\n";
            string an;
            cin>>an;
            if(an=="TAK") r=mid;
            else l=mid+1;
        }
        cout<<"1 "<<l+1<<" "<<x+1<<"\n";
        string an;
        cin>>an;
        if(an=="TAK") y=l;
    }
    if(y==-1)
    {
        l=x+1, r=n-1;
        while(r-l>0)
        {
            int mid=(l+r)/2;
            cout<<"1 "<<mid+1<<" "<<mid+2<<"\n";
            string an;
            cin>>an;
            if(an=="TAK") r=mid;
            else l=mid+1;
        }
        y=l;
    }
    cout<<"2 "<<x+1<<" "<<y+1;
}