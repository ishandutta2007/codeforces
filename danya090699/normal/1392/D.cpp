#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q=0;
        string s;
        cin>>n>>s;
        char sy=s.back();
        while(s.size() and s.back()==sy) q++, s.pop_back();
        if(q==n) printf("%d\n", n/3+(n%3>0));
        else
        {
            string s2;
            for(int a=0; a<q; a++) s2.push_back(sy);
            s2+=s;
            int yk=0, an=0;
            while(yk<n)
            {
                char sy=s2[yk];
                int q=0;
                while(yk<n and s2[yk]==sy) yk++, q++;
                an+=q/3;
            }
            printf("%d\n", an);
        }
    }
}