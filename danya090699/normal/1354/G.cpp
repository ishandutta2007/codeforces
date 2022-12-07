#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
string que(int l1, int r1, int l2, int r2)
{
    cout<<"? "<<r1-l1+1<<" "<<r2-l2+1<<"\n";
    for(int a=l1; a<=r1; a++) cout<<a<<" ";
    cout<<"\n";
    for(int a=l2; a<=r2; a++) cout<<a<<" ";
    cout<<"\n";
    string re;
    cin>>re;
    return re;
}
main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, k, q=1;
        cin>>n>>k;
        for(int a=0; a<20; a++)
        {
            int i=rnd()%(n-1)+2;
            if(que(1, 1, i, i)=="SECOND") q=0;
        }
        if(q)
        {
            while(q*2<n)
            {
                if(que(1, q, q+1, q*2)!="EQUAL") break;
                else q*=2;
            }
            int l=q, r=min(q*2, n);
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(que(1, mid-q, q+1, mid)=="EQUAL") l=mid;
                else r=mid;
            }
            cout<<"! "<<r<<"\n";
        }
        else cout<<"! 1\n";
    }
}