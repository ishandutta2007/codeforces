#include <bits/stdc++.h>
using namespace std;
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
        int yk=1;
        while(yk<n)
        {
            sp.push_back(1);
            while(yk+1<n and ar[yk]<ar[yk+1]) yk++, sp.back()++;
            yk++;
        }
        reverse(sp.begin(), sp.end());
        int q=1, an=0;
        while(sp.size())
        {
            int q2=0;
            an++;
            for(int a=0; a<q and sp.size(); a++)
            {
                q2+=sp.back();
                sp.pop_back();
            }
            q=q2;
        }
        printf("%d\n", an);
    }
}