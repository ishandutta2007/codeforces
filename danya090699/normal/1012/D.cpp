#include <bits/stdc++.h>
using namespace std;
vector <pair <char, int> > s[2];
vector <pair <int, int> > an;
int f(int q1, int q2)
{
    int l1=s[0].size()-q1+q2, l2=s[1].size()-q2+q1;
    if(l1==0 or l2==0) return 1e9;
    char sy1, sy2;
    if(q2)
    {
        sy1=s[1].back().first;
        if(q1<s[0].size())
        {
            if(s[0][s[0].size()-1-q1].first==s[1][s[1].size()-q2].first) l1--;
        }
    }
    else sy1=s[0][s[0].size()-1-q1].first;

    if(q1)
    {
        sy2=s[0].back().first;
        if(q2<s[1].size())
        {
            if(s[1][s[1].size()-1-q2].first==s[0][s[0].size()-q1].first) l2--;
        }
    }
    else sy2=s[1][s[1].size()-1-q2].first;

    int re=0;
    if(sy1==sy2)
    {
        re++;
        if(l1>l2) l1--;
        else l2--;
    }
    re+=max(l1, l2)-1;
    return re;
}
void cha(int q1, int q2)
{
    int q[2]={q1, q2};
    an.push_back(make_pair(0, 0));
    vector <pair <char, int> > sp[2];
    for(int i=0; i<2; i++)
    {
        while(q[i])
        {
            if(i==0) an.back().first+=s[i].back().second;
            else an.back().second+=s[i].back().second;
            sp[i^1].push_back(s[i].back());
            s[i].pop_back(), q[i]--;
        }
    }
    for(int i=0; i<2; i++)
    {
        while(sp[i].size())
        {
            if(s[i].size())
            {
                if(s[i].back().first!=sp[i].back().first) s[i].push_back(sp[i].back());
                else s[i].back().second+=sp[i].back().second;
            }
            else s[i].push_back(sp[i].back());
            sp[i].pop_back();
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=0; a<2; a++)
    {
        string t;
        cin>>t;
        for(int b=t.size()-1; b>=0; b--)
        {
            char sy=t[b];
            if(s[a].size())
            {
                if(s[a].back().first!=sy) s[a].push_back(make_pair(sy, 1));
                else s[a].back().second++;
            }
            else s[a].push_back(make_pair(sy, 1));
        }
    }
    int bq1=0, bq2=0, be=f(0, 0);
    for(int a=0; a<4; a++)
    {
        for(int b=0; b<=max(s[0].size(), s[1].size()); b++)
        {
            if(a<=s[0].size() and b<=s[1].size())
            {
                int cu=1+f(a, b);
                if(cu<be)
                {
                    be=cu, bq1=a, bq2=b;
                }
            }
            if(b<=s[0].size() and a<=s[1].size())
            {
                int cu=1+f(b, a);
                if(cu<be)
                {
                    be=cu, bq1=b, bq2=a;
                }
            }
        }
    }
    //cout<<bq1<<" "<<bq2<<" "<<be;
    if(!(bq1==0 and bq2==0)) cha(bq1, bq2);
    if(s[0].back().first==s[1].back().first)
    {
        if(s[0].size()>s[1].size()) cha(1, 0);
        else cha(0, 1);
    }
    while(s[0].size()>1 or s[1].size()>1) cha(1, 1);

    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
}