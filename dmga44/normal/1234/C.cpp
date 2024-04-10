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

pii solve(pii x,int t,int i,int j)
{
    if(x==pii(1,0))
    {
        if(t==1)
            return pii(i+1,j);
        else
            return pii(i,1-j);
    }

    if(t==1)
        return pii(-1,-1);
    else
        return pii(i+1,j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    string s;
//    cin >> s;
//    int n=s.size();
//    for(int i=0;i<n;i++)
//        update(i+1,s[i]-'a',1);
//    int q;
//    cin >> q;
//    while(q--)
//    {
//        int t;
//        cin >> t;
//        if(t==1)
//        {
//            int p;
//            char c;
//            cin >> p >> c;
//            update(p,s[p-1]-'a',-1);
//            s[p-1]=c;
//            update(p,s[p-1]-'a',1);
//        }
//        else
//        {
//            int l,r;
//            cin >> l >> r;
//            int res=0;
//            for(int i=0;i<26;i++)
//            {
//                int x=query(r,i)-query(l-1,i);
//                if(x)
//                    res++;
//            }
//            db(res)
//        }
//    }

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<bool> mk[2];
        string s[2];
        cin >> s[0] >> s[1];

        mk[0].resize(n+5);
        mk[1].resize(n+5);
        pii ini=pii(0,0),ant=pii(-1,0);
        while(ini!=pii(-1,-1))
        {
//            cout << ini.first << ' ' << ini.second << '\n';
            if(ini.first>n)
                break;
            mk[ini.second][ini.first]=1;
            int t;
            if(s[ini.second][ini.first]<'3')
                t=1;
            else
                t=3;
            pii curr=solve(pii(ini.first-ant.first,ini.second-ant.second),t,ini.first,ini.second);
            ant=ini;
            ini=curr;
        }

//        ini=pii(0,0),ant=pii(0,-1);
//        while(ini!=pii(-1,-1))
//        {
//            cout << ini.first << ' ' << ini.second << '\n';
//            if(ini.first>n)
//                break;
//            mk[ini.second][ini.first]=1;
//            int t;
//            if(s[ini.second][ini.first]<'3')
//                t=1;
//            else
//                t=3;
//            pii curr=solve(pii(ini.first-ant.first,ini.second-ant.second),t,ini.first,ini.second);
//            ant=ini;
//            ini=curr;
//        }

        if(mk[1][n])
            db("YES")
        else
            db("NO")
    }

    return 0;
}
/**
1
2
46
54
**/