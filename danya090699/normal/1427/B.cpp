#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, q=0;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <pair <int, int> > sp;
        int yk=0;
        while(yk<n)
        {
            if(s[yk]=='W')
            {
                int l=yk;
                while(yk<n and s[yk]=='W') yk++, q++;
                sp.push_back({l, yk-1});
            }
            else yk++;
        }
        k=min(n-q, k);
        vector <int> ar;
        for(int a=0; a+1<sp.size(); a++) ar.push_back(sp[a+1].first-sp[a].second-1);
        sort(ar.begin(), ar.end(), greater <int>());
        int an=(q+k)*2;
        while(ar.size() and ar.back()<=k)
        {
            k-=ar.back();
            ar.pop_back();
        }
        if(an) an-=ar.size()+1;
        cout<<an<<"\n";
    }
}