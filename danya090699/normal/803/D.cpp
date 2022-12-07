#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, inf=1e9, ma=0;
    cin>>k;
    vector <int> s(1);
    s[0]=0;
    string st;
    getline(cin, st);
    getline(cin, st);
    for(int a=0; a<st.size(); a++)
    {
        s.back()++;
        if(st[a]==' ' or st[a]=='-') s.push_back(0);
    }
    for(int a=0; a<s.size(); a++)
    {
        ma=max(ma, s[a]);
    }
    int l=0, r=1e6+10;
    while(r-l>1)
    {
        int mi=(l+r)/2, q=0, yk=0;
        if(mi<ma) l=mi;
        else
        {
            while(yk<s.size())
            {
                int le=0;
                while(yk<s.size())
                {
                    if(le+s[yk]<=mi)
                    {
                        le+=s[yk], yk++;
                    }
                    else break;
                }
                q++;
            }
            if(q>k) l=mi;
            else r=mi;
        }
    }
    cout<<r;
}