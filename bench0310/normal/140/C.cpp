#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    priority_queue<array<int,2>> q;
    for(auto [a,c]:m) q.push({c,a});
    int t=0;
    if(q.size()>=3)
    {
        auto [c1,a1]=q.top();
        q.pop();
        int c2=q.top()[0];
        t=min({n/3,(n-c1)/2,n-c1-c2});
        q.push({c1,a1});
    }
    vector<array<int,3>> res;
    while(q.size()>=3)
    {
        array<int,3> a,c;
        for(int i=0;i<3;i++)
        {
            c[i]=q.top()[0];
            a[i]=q.top()[1];
            q.pop();
        }
        array<int,3> r;
        for(int i=0;i<3;i++)
        {
            r[i]=a[i];
            c[i]--;
            if(c[i]>0) q.push({c[i],a[i]});
        }
        sort(r.begin(),r.end(),greater<int>());
        res.push_back(r);
    }
    assert((int)res.size()==t);
    cout << res.size() << "\n";
    for(auto [a,b,c]:res) cout << a << " " << b << " " << c << "\n";
    return 0;
}