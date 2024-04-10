#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int P=(int) 1e7+19;
const int M=(int) 1e9+7;

struct thing
{
        int value;
        int mass;
        int ind;
};

const int Q=30000+7;
int n, k, q, first[Q], last[Q];
thing v[Q];
bool dead[Q];
int ques[Q], top;

int getbefore(int i)
{
        int l=1, r=top, sol=0;
        while (l<=r)
        {
                int m=(l+r)/2;
                if (ques[m]<=i)
                {
                        sol=m;
                        l=m+1;
                }
                else
                        r=m-1;
        }
        return sol;
}

vector<thing> events[4*Q];

void add(int v, int tl, int tr, int l, int r, thing a)
{
        if (tr<l || r<tl)
                return;
        if (l<=tl && tr<=r)
        {
                events[v].push_back(a);
                return;
        }
        int tm=(tl+tr)/2;
        add(2*v, tl, tm, l, r, a);
        add(2*v+1, tm+1, tr, l, r, a);
}

void dfs(int v, int tl, int tr, vector<int> state)
{
        assert((int) state.size()==k+1);
        for (auto &it : events[v])
        {
                for (int j=k; j>=it.mass; j--)
                {
                        state[j]=max(state[j], state[j-it.mass]+it.value);
                }
        }

        if (tl==tr)
        {
                int sol=0, cur=1;
                for (int j=1; j<=k; j++)
                {
                        sol=(sol+(ll) state[j]*cur)%M;
                        cur=(ll) cur*P%M;
                }
                cout<<sol<<"\n";

                return;
        }
        int tm=(tl+tr)/2;
        dfs(2*v, tl, tm, state);
        dfs(2*v+1, tm+1, tr, state);
}

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

       // freopen ("input", "r", stdin);

        cin>>n>>k;
        for (int i=1; i<=n; i++)
        {
                first[i]=0;
                cin>>v[i].value>>v[i].mass;
                v[i].ind=i;
        }
        cin>>q;
        for (int i=1; i<=q; i++)
        {
                int type;
                cin>>type;
                if (type==1)
                {
                        n++;
                        first[n]=i;
                        cin>>v[n].value>>v[n].mass;
                        v[n].ind=n;
                }
                if (type==2)
                {
                        int ind;
                        cin>>ind;
                        assert(1<=ind && ind<=n);
                        assert(!dead[ind]);
                        last[ind]=i;
                        dead[ind]=1;
                }
                if (type==3)
                {
                        ques[++top]=i;
                }
        }
        assert(top>0);
        /**cout<<" -------> ";
        for (int i=1; i<=top; i++)
        {
                cout<<ques[i]<<" ";
        }
        cout<<"\n";**/
        for (int i=1; i<=n; i++)
        {
                if (!last[i])
                        last[i]=(int) 1e9;
                int i1=getbefore(last[i]);
                int i2=getbefore(first[i]-1)+1;
                if (i2<=i1)
                {
                       /// cout<<i<<" : "<<i1<<" and "<<i2<<"\n";
                        add(1, 1, top, i2, i1, v[i]);
                }
        }
        vector<int> state(k+1, 0);
        dfs(1, 1, top, state);
}