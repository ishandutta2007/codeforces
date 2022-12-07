#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, d;
        cin>>n>>d;
        int ar[n];
        for(int a=0; a<n; a++) cin>>ar[a];
        for(int a=1; a<n; a++)
        {
            while(d>=a and ar[a]) ar[a]--, ar[0]++, d-=a;
        }
        cout<<ar[0]<<"\n";
    }
}