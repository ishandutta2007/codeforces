#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(a)
        {
            if(ar[a-1]==1 and ar[a]==2)
            {
                an+=3;
                if(a>1 and ar[a-2]==3) an--;
            }
            else if(ar[a-1]==1 and ar[a]==3) an+=4;
            else if(ar[a-1]==2 and ar[a]==1) an+=3;
            else if(ar[a-1]==3 and ar[a]==1) an+=4;
            else
            {
                cout<<"Infinite";
                return 0;
            }
        }
    }
    cout<<"Finite\n"<<an;
}