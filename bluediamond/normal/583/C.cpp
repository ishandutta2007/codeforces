#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500+7;

multiset<int>g;

int v[N],y;

int gcd(int a,int b)
{
        if(b==0)
        {
                return a;
        }
        else
        {
                return gcd(b,a%b);
        }
}

void push(int x)
{
        v[++y]=x;
        for(int i=1;i<y;i++)
        {
                int val=gcd(v[y],v[i]);
                auto it=g.find(val);
                g.erase(it);
                it=g.find(val);
                g.erase(it);
        }
        auto it=g.find(v[y]); g.erase(it);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        for(int i=1;i<=n*n;i++)
        {
                int x;
                cin>>x;
                g.insert(x);
        }
        while(g.size()>0)
        {
                auto it=g.end();
                it--;
                push(*it);
        }
        sort(v+1,v+n+1);
        for(int i=1;i<=n;i++)
        {
                cout<<v[i]<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

**/