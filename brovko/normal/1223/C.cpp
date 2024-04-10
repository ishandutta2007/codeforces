#include <bits/stdc++.h>
using namespace std;
long long q, n, a, x, b, y, c, p[200005], s, lcm, ka, kb;
vector <long long> v[105], ans;

int main()
{
    cin >> q;
    for(int test=0;test<q;test++)
    {
        for(int i=0;i<=n;i++)
            p[i]=0;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> c;
            v[test].push_back(c);
        }
        sort(v[test].begin(), v[test].end());
        for(int i=1;i<=n;i++)
        p[i]=p[i-1]+v[test][i-1];
        cin >> x >> a >> y >> b >> s;
        if(x>y)
        {
            swap(x, y);
            swap(a, b);
        }
        lcm=0;
        ka=0;
        kb=0;
        for(int i=1;i<=n;i++)
        {
            if(i%a==0 && i%b==0)
                lcm++;
            if(i%a==0 && i%b)
                ka++;
            if(i%b==0 && i%a)
                kb++;
            if((p[n]-p[n-lcm])/100*(x+y)+(p[n-lcm]-p[n-lcm-kb])/100*y+(p[n-lcm-kb]-p[n-lcm-kb-ka])/100*x>=s && ans.size()<=test)
                ans.push_back(i);
        }
        if(ans.size()<=test)
            ans.push_back(-1);
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << "\n";
    return 0;
}