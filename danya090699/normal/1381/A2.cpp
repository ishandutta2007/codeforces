#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        deque <pair <int, int> > qu;
        string s;
        cin>>s;
        int yk=0;
        while(yk<n)
        {
            qu.push_back({s[yk]-'0', 0});
            char sy=s[yk];
            while(yk<n and s[yk]==sy) qu.back().second++, yk++;
        }
        string t;
        cin>>t;
        int i=0;
        vector <int> an;
        for(int a=n-1; a>=0; a--)
        {
            int sy=t[a]-'0';
            if(i==0)
            {
                if(qu.back().first==sy^i)
                {
                    qu.back().second--;
                    if(qu.back().second==0) qu.pop_back();
                }
                else
                {
                    if(qu.back().first==qu.front().first)
                    {
                        i^=1, qu.front().second--;
                        if(qu.front().second==0) qu.pop_front();
                        an.push_back(a+1);
                    }
                    else
                    {
                        int q=qu.back().second;
                        qu.pop_back();
                        qu.front().second+=q;
                        i^=1, an.push_back(a+1-q);
                        i^=1, an.push_back(a+1);
                        qu.back().second--;
                        if(qu.back().second==0) qu.pop_back();
                    }
                }
            }
            else
            {
                if(qu.front().first==sy^i)
                {
                    qu.front().second--;
                    if(qu.front().second==0) qu.pop_front();
                }
                else
                {
                    if(qu.front().first==qu.back().first)
                    {
                        i^=1, qu.back().second--;
                        if(qu.back().second==0) qu.pop_back();
                        an.push_back(a+1);
                    }
                    else
                    {
                        int q=qu.front().second;
                        qu.pop_front();
                        qu.back().second+=q;
                        i^=1, an.push_back(a+1-q);
                        i^=1, an.push_back(a+1);
                        qu.front().second--;
                        if(qu.front().second==0) qu.pop_front();
                    }
                }
            }
        }
        cout<<an.size();
        for(int a=0; a<an.size(); a++) cout<<" "<<an[a];
        cout<<"\n";
    }
}