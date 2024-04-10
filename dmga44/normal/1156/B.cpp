#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int f[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++)
            f[s[i]-'a']++;
        vector<pii> v;
        for(int i=0;i<26;f[i]=0,i++)
            if(f[i])
                v.push_back(pii(i,f[i]));
        int x=v.size();
        pii ok=pii(-1,-1);
        for(int i=0;i<x;i+=2)
            for(int j=1;j<x;j+=2)
                if(abs(v[j].first-v[i].first)!=1 && ok==pii(-1,-1))
                    ok=pii(i,j);
        string res="";
        for(int i=0;i<x;i+=2)
            if(i!=ok.first)
                for(int j=0;j<v[i].second;j++)
                    res=(res+char('a'+v[i].first));
        if(ok!=pii(-1,-1))
        {
            for(int j=0;j<v[ok.first].second;j++)
                res=(res+char('a'+v[ok.first].first));
            for(int j=0;j<v[ok.second].second;j++)
                res=(res+char('a'+v[ok.second].first));
        }
        for(int i=1;i<x;i+=2)
            if(i!=ok.second)
                for(int j=0;j<v[i].second;j++)
                    res=(res+char('a'+v[i].first));
        bool okk=1;
        for(int i=0;i<res.size()-1;i++)
            okk&=(abs(res[i]-res[i+1])!=1);

        if(okk)
            db(res)
        else
            db("No answer")
    }

    return 0;
}