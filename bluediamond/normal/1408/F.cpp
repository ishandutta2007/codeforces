#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<pair<int,int>> q;
int n;

void op(int i,int j)
{
        q.push_back({i,j});
}

void f(int l,int r)
{
        if (l>=r)
                return;
        int len=(r-l+1);
        if (len%2==0)
        {
                int m=(l+r)/2;
                f(l,m);
                f(m+1,r);
                for (int j=0;j<len/2;j++)
                        op(l+j,l+len/2+j);
        }
        else
        {
                r--;
                int m=(l+r)/2;
                f(l,m);
                f(m+1,r);
                for (int j=0;j<len/2;j++)
                        op(l+j,l+len/2+j);
                r++;
                for (int j=l;j<r;j++)
                        op(j,r);
        }
}

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n;
        int k=log2(n);
        k=(1<<k);
        f(1,k);
        f(n-k+1,n);
        cout<<(int) q.size()<<"\n";
        for (auto &it:q)
                cout<<it.first<<" "<<it.second<<"\n";
}