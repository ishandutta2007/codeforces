#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 100005

int abi[26][MAXN];

void update(int p,int c,int v)
{
    while(p<MAXN)
    {
        abi[c][p]+=v;
        p+=(p&-p);
    }
}

int query(int p,int c)
{
    int res=0;
    while(p)
    {
        res+=abi[c][p];
        p-=(p&-p);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++)
        update(i+1,s[i]-'a',1);
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int p;
            char c;
            cin >> p >> c;
            update(p,s[p-1]-'a',-1);
            s[p-1]=c;
            update(p,s[p-1]-'a',1);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            int res=0;
            for(int i=0;i<26;i++)
            {
                int x=query(r,i)-query(l-1,i);
                if(x)
                    res++;
            }
            db(res)
        }
    }

    return 0;
}