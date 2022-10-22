#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 105

string s[MAXN];
map<int,int> m;
vector<int> vs[MAXN];

bool is_substr(int x,int y)
{
    for(int i=0;i<s[x].size()-s[y].size()+1;i++)
    {
        bool f=1;
        for(int j=0;j<s[y].size();j++)
            f&=(s[x][i+j]==s[y][j]);
        if(f)
            return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        if(m[s[i].size()] && s[m[s[i].size()]-1]!=s[i])
        {
            db("NO")
            return 0;
        }
        m[s[i].size()]=i+1;
        vs[s[i].size()].push_back(i);
    }
    vector<pii> v;
    for(auto y : m)
        v.push_back(y);

    sort(v.begin(),v.end());

    for(int i=0;i<v.size()-1;i++)
        if(!is_substr(v[i+1].second-1,v[i].second-1))
        {
            db("NO")
            return 0;
        }

    db("YES")
    for(int i=0;i<MAXN;i++)
        for(auto yy : vs[i])
            db(s[yy])

    return 0;
}