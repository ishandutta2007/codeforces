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
        string s;
        cin>>s;
        int lq=0, rq=0, q=0;
        int n=s.size();
        while(q<n and s[q]==s[n-1-q]) q++;

        int p1[n], p2[n-1], l=-1, r=-1;
        for(int a=0; a<n; a++)//p1[a] is for odd palindromes with center in a
        {
            p1[a]=0;
            if(a<=r) p1[a]=min(p1[l-(a-l)], r-a);
            while(p1[a]<a and p1[a]<(n-(a+1)))
            {
                if(s[a-(p1[a]+1)]==s[a+(p1[a]+1)]) p1[a]++;
                else break;
            }
            if(r<a+p1[a])
            {
                r=a+p1[a], l=a;
            }

            if(a<n/2 and q+p1[a]>=a)
            {
                int l=a+1+p1[a], r=a-p1[a];
                if(l+r>lq+rq) lq=l, rq=r;
            }
            if(a>=n/2 and q+p1[a]>=n-a-1)
            {
                int l=n-(a+1)-p1[a], r=(n-a)+p1[a];
                if(l+r>lq+rq) lq=l, rq=r;
            }
        }
        l=-1, r=-1;
        for(int a=0; a<n-1; a++)//p2[a] is for even palindromes with center between a and a+1
        {
            p2[a]=0;
            if(a<r) p2[a]=min(p2[l-(a-l)], r-a);
            while(p2[a]<(a+1) and p2[a]<(n-(a+1)))
            {
                if(s[a-p2[a]]==s[a+(p2[a]+1)]) p2[a]++;
                else break;
            }
            if(r<a+p2[a])
            {
                r=a+p2[a], l=a;
            }

            if(a<n/2 and q+p2[a]>=a+1)
            {
                int l=a+1+p2[a], r=a+1-p2[a];
                if(l+r>lq+rq) lq=l, rq=r;
            }
            if(a>=n/2 and q+p2[a]>=n-1-a)
            {
                int l=n-1-a-p2[a], r=n-1-a+p2[a];
                //if(a==2) cout<<l<<" "<<r<<"\n";
                if(l+r>lq+rq) lq=l, rq=r;
            }
        }
        cout<<s.substr(0, lq)<<s.substr(n-rq, rq);
        cout<<"\n";
    }
}