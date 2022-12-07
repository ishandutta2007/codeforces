#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x;
        cin>>x;
        int l=x-1, r=x*(x-1)/2+1;
        while(r-l>1)
        {
            int mi=(l+r)/2;
            int cq=mi/2+mi%2+1;
            int q=x-(cq-1);
            if(q>0)
            {
                if(q*(q-1)/2>=mi/2) l=mi;
                else r=mi;
            }
            else r=mi;
        }
        cout<<l<<"\n";
    }
}