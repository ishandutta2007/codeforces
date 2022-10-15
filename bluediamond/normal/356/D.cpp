#include <bits/stdc++.h>

using namespace std;

const int N=70000+7;

/// ._Find_first()
/// ._Find_next()

int n, s, firstTime[N], init[N];
pair<int, int> a[N];
bitset<N> ok, oknew, newbits;
bool use[N];
int node[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);


        cin>>n>>s;
        for (int i=1; i<=n; i++)
        {
                cin>>a[i].first;
                a[i].second=i;
                init[i]=a[i].first;
        }
        sort(a+1, a+n+1);
        if (a[n].first>s)
        {
                cout<<"-1\n";
                return 0;
        }
        s-=a[n].first;
        n--;

        ok[0]=1;
        for (int i=1; i<=n; i++)
        {
                int x=a[i].first, ind=a[i].second;
                oknew=ok|(ok<<x);
                newbits=ok^oknew;
                ok=oknew;
                for (int j=newbits._Find_first(); j<N; j=newbits._Find_next(j))
                {
                        firstTime[j]=i;
                }
        }
        if (!ok[s])
        {
                cout<<"-1\n";
                return 0;
        }

        while (s)
        {
                int j=firstTime[s];
                use[j]=1;
                s-=a[j].first;
        }
        n++;

        for (int i=1; i<=n; i++)
                node[i]=-1;

        int last=n;
        for (int i=n-1; i>=1; i--)
        {
                if (!use[i])
                {
                        node[a[last].second]=a[i].second;
                        last=i;
                }
        }

        for (int i=1; i<=n; i++)
        {
                if (node[i]==-1)
                {
                        cout<<init[i]<<" 0"<<"\n";
                }
                else
                {
                        cout<<init[i]-init[node[i]]<<" 1 "<<node[i]<<"\n";
                }
        }

        return 0;
}