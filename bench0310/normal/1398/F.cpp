#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct opt
{
    vector<set<int>> s;
    vector<int> l;
    vector<int> r;
    int n;
    opt(string t)
    {
        n=t.size();
        t="$"+t;
        int c=1;
        s.resize(n+1);
        l.assign(n+1,1);
        r.assign(n+1,n);
        s[1].insert(n);
        for(int i=n-1;i>=1;i--)
        {
            if(t[i]==t[i+1]) c++;
            else c=1;
            s[c].insert(i);
        }
        char val=t[n];
        for(int i=n-1;i>=1;i--)
        {
            if(t[i]==val) r[i]=r[i+1];
            else
            {
                val=t[i];
                r[i]=i;
            }
        }
        val=t[1];
        for(int i=2;i<=n;i++)
        {
            if(t[i]==val) l[i]=l[i-1];
            else
            {
                val=t[i];
                l[i]=i;
            }
        }
    }
    int nxt(int pos,int sz) //pos is eligible
    {
        auto it=s[sz].lower_bound(pos);
        if(it==s[sz].end()) return -1;
        int x=*it;
        int a=max(pos,l[x]);
        return a+sz;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t=s;
    for(int i=0;i<n;i++) if(t[i]=='?') t[i]='0';
    opt a(t);
    t=s;
    for(int i=0;i<n;i++) if(t[i]=='?') t[i]='1';
    opt b(t);
    for(int i=1;i<=n;i++)
    {
        int now=1;
        int res=0;
        while(1)
        {
            int one=a.nxt(now,i);
            int two=b.nxt(now,i);
            if(one==-1&&two==-1) break;
            else if(one==-1)
            {
                res++;
                now=two;
            }
            else if(two==-1)
            {
                res++;
                now=one;
            }
            else
            {
                res++;
                now=min(one,two);
            }
        }
        cout << res << " \n"[i==n];
    }
    return 0;
}