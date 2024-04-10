#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<pair<multiset<int>,int>,bool> m;

void opt(multiset<int> &s)
{
    s.erase(0);
}

bool solve(multiset<int> s,int t)
{
    opt(s);
    if(s.empty()) return 0;
    if(m.find({s,t})!=m.end()) return m[{s,t}];
    bool res=0;
    for(int a:s)
    {
        multiset<int> ns=s;
        ns.erase(ns.find(a));
        ns.insert(t);
        int nt=a-1;
        if(solve(ns,nt)==0) res=1;
    }
    return (m[{s,t}]=res);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        multiset<int> s;
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            s.insert(a);
        }
        int x=0;
        int mv=0;
        while(!s.empty())
        {
            int y=(*s.rbegin());
            s.erase(s.find(y));
            if(x>0) s.insert(x);
            x=y-1;
            mv^=1;
        }
        if(mv==1) cout << "T\n";
        else cout << "HL\n";
    }
    return 0;
}