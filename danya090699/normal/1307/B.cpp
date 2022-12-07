#include <bits/stdc++.h>
using namespace std;
const int inf=2e9;
main()
{
	//freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, x;
        cin>>n>>x;
        int an=inf, ma=0;
        for(int a=0; a<n; a++)
        {
            int y;
            scanf("%d", &y);
            if(y==x) an=1;
            ma=max(ma, y);
        }
        if(an!=1) an=max(2, x/ma+(x%ma>0));
        cout<<an<<"\n";
    }
}