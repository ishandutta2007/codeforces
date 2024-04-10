#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 100005

int last[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s,t;
        cin >> s >> t;
        int n=s.size(),l=t.size();
        for(int i=0;i<26;i++)
            last[n][i]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
                last[i][j]=last[i+1][j];
            last[i][s[i]-'a']=i+1;
        }

        int act=0,res=0,ok=1;
        for(int i=0;i<l && ok;i++)
        {
            if(last[act][t[i]-'a'])
                act=last[act][t[i]-'a'];
            else
            {
                if(act!=0)
                {
                    res++;
                    act=0;
                }
                if(!last[0][t[i]-'a'])
                    ok=0;
                else
                    act=last[0][t[i]-'a'];
            }
        }
        res++;

        if(ok)
            db(res)
        else
            db(-1)
    }

    return 0;
}