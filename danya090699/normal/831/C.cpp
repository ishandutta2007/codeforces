//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, pr=0, an=0;
    cin>>k>>n;
    int di[k], po[n];
    for(int a=0; a<k; a++)
    {
        int x;
        cin>>x;
        di[a]=pr+x, pr=di[a];
    }
    sort(di, di+k);
    for(int a=0; a<n; a++) cin>>po[a];
    sort(po, po+n);
    for(int a=0; a<=k-n; a++)
    {
        int st=po[0]-di[a], pos=1, yk=a+1;
        if(a!=0)
        {
            if(di[a]==di[a-1]) pos=0;
        }
        for(int b=1; b<n; b++)
        {
            bool fo=0;
            while(yk<k)
            {
                if(st+di[yk]==po[b])
                {
                    fo=1;
                    break;
                }
                else yk++;
            }
            if(fo==0) pos=0;
        }
        an+=pos;
    }
    cout<<an;
}