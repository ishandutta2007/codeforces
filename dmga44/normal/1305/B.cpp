#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<vector<int> > ans;
    int n=s.size();
    vector<int> t1,t2;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            t1.push_back(i);
        else
            t2.push_back(i);
    }

    reverse(t2.begin(),t2.end());

    int p=0;
    ans.push_back({});
    while(p<t1.size() && p<t2.size() && t1[p]<t2[p])
    {
        ans[0].push_back(t1[p]);
        ans[0].push_back(t2[p]);
        p++;
    }

    if(p)
    {
        db(1)
        db(ans[0].size())
        sort(ans[0].begin(),ans[0].end());
        for(auto y : ans[0])
            cout << y+1 << ' ';
        cout << '\n';
    }
    else
        db(0)
    return 0;
}