//  228

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define pf push_front
#define F first
#define re return
#define S second
#define ll long long
#define f(i) return cout<<i<<"\n",0;
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define lp(i, a, b) for (int i=(a);i<=(int)(b);++i)
#define lp2(i, a, b) for (int i=(a);i>=(b);--i)
#define clr(c, x) memset(c,x,sizeof(c))
#define allr(v) v.rbegin(),v.rend()
#define all(v) v.begin(),v.end()
#define re return
const int N = 2e5 + 5, mod = (int) 1e9 + 7;
map<string,int>mp;
vector<string>v[100*15+5];
set<string>st;
int main()
{
    FAST
    //freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    int m;
    cin>>m;
    string z;
    getline(cin,z);
    //cout << m << "\n";
    while(m--)
    {
        string t;
        getline(cin,t);
        //cout << t << "\n";
        string ss;
        vector<string> word;
        for (auto u:t)
        {
            if (u==' ')
            {
                word.pb(ss);
                ss.clear();
                continue;
            }
            ss.pb(u);
        }
        word.pb(ss);
        //for (auto u:word) cout << u << "\n";
        string tt = word.back();
        word.pop_back();
        word.back().pop_back();
        word.back().pop_back();
        if (word[0]!=s)
            st.insert(word[0]);
        if (word.back()!=s)
            st.insert(word.back());
        if (tt=="wall")
        {
            if (word[0]!=s&&word.back()==s)
                mp[word[0]]+=15;
            if (word.back()!=s&&word[0]==s)
                mp[word.back()]+=15;
        }
        else
        {
            if (word.size()==4)
            {
                if (word[0]!=s&&word.back()==s)
                    mp[word[0]]+=10;
                if (word.back()!=s&&word[0]==s)
                    mp[word.back()]+=10;
            }
            else
            {
                if (word[0]!=s&&word.back()==s)
                    mp[word[0]]+=5;
                if (word.back()!=s&&word[0]==s)
                    mp[word.back()]+=5;
            }
        }
    }
    for (auto u:st) v[mp[u]].pb(u);
    lp2(i,100*15+3,0)
    {
        if (v[i].size())
        {
            sort(all(v[i]));
            for (auto u:v[i]) cout << u << "\n";
        }

    }
    return 0;
}