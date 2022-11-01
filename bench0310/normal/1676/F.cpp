#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            m[a]++;
        }
        vector<int> v;
        for(auto [a,c]:m) if(c>=k) v.push_back(a);
        int l=0;
        int sz=v.size();
        array<int,3> res={-1,0,0};
        while(l<sz)
        {
            int r=l;
            while(r+1<sz&&v[r]+1==v[r+1]) r++;
            res=max(res,{r-l+1,v[l],v[r]});
            l=r+1;
        }
        if(res[0]!=-1) cout << res[1] << " " << res[2] << "\n";
        else cout << "-1\n";
    }
    return 0;
}