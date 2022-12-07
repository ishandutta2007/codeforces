#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> su[10];
multiset <int, greater <int>> ma[10];
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, q;
        scanf("%lld%lld", &n, &q);
        int ar[n];
        for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
        vector <int> de;
        int n2=n;
        for(int a=2; a*a<=n2; a++)
        {
            if(n2%a==0)
            {
                de.push_back(a);
                while(n2%a==0) n2/=a;
            }
        }
        if(n2>1) de.push_back(n2);
        for(int i=0; i<de.size(); i++)
        {
            int k=n/de[i];
            for(int a=0; a<k; a++)
            {
                su[i].push_back(0);
                for(int b=a; b<n; b+=k) su[i][a]+=ar[b];
                ma[i].insert(su[i][a]);
            }
        }
        for(int a=0; a<=q; a++)
        {
            if(a)
            {
                int p, x;
                scanf("%lld%lld", &p, &x);
                p--;
                for(int i=0; i<de.size(); i++)
                {
                    int k=n/de[i], os=p%k;
                    ma[i].erase(ma[i].find(su[i][os]));
                    su[i][os]+=x-ar[p];
                    ma[i].insert(su[i][os]);
                }
                ar[p]=x;
            }
            int an=0;
            for(int i=0; i<de.size(); i++)
            {
                int k=n/de[i];
                an=max(an, (*ma[i].begin())*k);
            }
            printf("%lld\n", an);
        }
        for(int i=0; i<de.size(); i++)
        {
            su[i].clear();
            ma[i].clear();
        }
    }
}