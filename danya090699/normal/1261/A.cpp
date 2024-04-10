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
        int n, k;
        string s, t;
        cin>>n>>k>>s;
        for(int a=0; a<n; a+=2) t+="()";
        if(k<n/2)
        {
            t[1]='(';
            t[(n/2-k)*2]=')';
        }
        vector <pair <int, int> > an;
        for(int a=0; a<n; a++)
        {
            if(s[a]!=t[a])
            {
                for(int b=a+1; ; b++)
                {
                    if(s[b]==t[a])
                    {
                        int l=a, r=b;
                        an.push_back({l+1, r+1});
                        while(l<r) swap(s[l], s[r]), l++, r--;
                        break;
                    }
                }
            }
        }
        cout<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
    }
}