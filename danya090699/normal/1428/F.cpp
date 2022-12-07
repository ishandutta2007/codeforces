#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    char s[n+1];
    scanf("%s", s);
    long long an=0;
    int yk=0;
    vector <pair <int, int> > st;
    vector <int> mul;
    while(yk<n)
    {
        if(s[yk]=='1')
        {
            int i=yk;
            while(s[yk]=='1') yk++;
            int len=yk-i;

            int p=upper_bound(st.begin(), st.end(), make_pair(len, -1), greater <pair <int, int> >())-st.begin()-1;
            if(p!=-1)
            {
                int l=st[p].second+(st[p].first-(len-1));
                mul.push_back(i-l+1);
            }
            else mul.push_back(i+1);

            for(int a=1; a<len; a++)
            {
                int p=upper_bound(st.begin(), st.end(), make_pair(a, -1), greater <pair <int, int> >())-st.begin()-1;
                if(p!=-1)
                {
                    int l=st[p].second+(st[p].first-(a-1));
                    //cout<<l<<" ";
                    an+=1ll*a*(i-l+1);
                }
                else an+=1ll*a*(i+1);
            }

            for(int a=1; a<=len-2; a++) an+=1ll*a*(len-1-a);

            while(st.size() and st.back().first<=len) st.pop_back();
            st.push_back({len, i});
        }
        else yk++;
    }

    yk=n-1;
    st.clear();

    //cout<<an<<" ";

    while(yk>=0)
    {
        if(s[yk]=='1')
        {
            int i=yk+1;
            while(s[yk]=='1') yk--;
            int len=i-(yk+1);

            int p=upper_bound(st.begin(), st.end(), make_pair(len+1, -1), greater <pair <int, int> >())-st.begin()-1;
            if(p!=-1)
            {
                int r=st[p].second-(st[p].first-len);
                an+=1ll*len*mul.back()*(r-i+1);
            }
            else an+=1ll*len*mul.back()*(n-i+1);

            mul.pop_back();

            for(int a=1; a<len; a++)
            {
                int p=upper_bound(st.begin(), st.end(), make_pair(a+1, -1), greater <pair <int, int> >())-st.begin()-1;
                //cout<<p<<" ";
                if(p!=-1)
                {
                    int r=st[p].second-(st[p].first-a);
                    //cout<<r<<" ";
                    an+=1ll*a*(r-i+1);
                }
                else an+=1ll*a*(n-i+1);
            }

            while(st.size() and st.back().first<=len) st.pop_back();
            st.push_back({len, i});
        }
        else yk--;
    }

    cout<<an;
}