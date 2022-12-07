#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n%2==0)
    {
        int ar[n][2];
        for(int a=0; a<n; a++) for(int i=0; i<2; i++) scanf("%d", &ar[a][i]);
        for(int a=0; a<n/2; a++)
        {
            int vx1=ar[a+1][0]-ar[a][0], vy1=ar[a+1][1]-ar[a][1];
            int vx2=ar[(a+n/2+1)%n][0]-ar[a+n/2][0], vy2=ar[(a+n/2+1)%n][1]-ar[a+n/2][1];
            if(vx1!=-vx2 or vy1!=-vy2)
            {
                cout<<"NO";
                return 0;
            }
        }
        cout<<"YES";
    }
    else cout<<"NO";
}