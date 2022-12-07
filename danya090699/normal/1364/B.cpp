#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int a=0; a<n; a++) scanf("%d", &ar[a]);
        vector <int> sp;
        for(int a=0; a<n; a++)
        {
            if(a and a+1<n)
            {
                if(!((ar[a-1]<ar[a] and ar[a]<ar[a+1]) or (ar[a-1]>ar[a] and ar[a]>ar[a+1])))
                {
                    sp.push_back(ar[a]);
                }
            }
            else sp.push_back(ar[a]);
        }
        printf("%d\n", sp.size());
        for(int a=0; a<sp.size(); a++) printf("%d ", sp[a]);
        printf("\n");
    }
}