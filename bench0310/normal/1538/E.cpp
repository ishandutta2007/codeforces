#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    ll n;
    string l,r;
    ll cnt;
    obj(){n=cnt=0;}
    obj(string s)
    {
        n=s.size();
        cnt=0;
        for(int i=0;i+3<n;i++) cnt+=(s.substr(i,4)=="haha");
        l=s.substr(0,3);
        r=s.substr(max(0,int(n)-3),3);
    }
    friend obj operator+(const obj &a,const obj &b)
    {
        obj c;
        c.n=a.n+b.n;
        c.cnt=a.cnt+b.cnt;
        string tmp=a.r+b.l;
        int sz=tmp.size();
        for(int i=0;i+3<sz;i++) c.cnt+=(tmp.substr(i,4)=="haha");
        tmp=a.l+b.l;
        c.l=tmp.substr(0,3);
        tmp=a.r+b.r;
        c.r=tmp.substr(max(0,int(tmp.size())-3),3);
        return c;
    }
};

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
        map<string,obj> m;
        ll res=0;
        while(n--)
        {
            string var,op;
            cin >> var >> op;
            if(op==":=")
            {
                string s;
                cin >> s;
                m[var]=obj(s);
            }
            else
            {
                string one,two;
                cin >> one >> op >> two;
                m[var]=(m[one]+m[two]);
            }
            res=m[var].cnt;
        }
        cout << res << "\n";
    }
    return 0;
}