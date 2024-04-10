#include <bits/stdc++.h>

using namespace std;

int sol=(int) 1e9+7;
int op,lim;

int ask(int r,int c)
{
        op++;
        if (op==lim)
        {
                cout<<"! "<<sol<<endl;
                exit(0);
        }
        cout<<"? "<<r<<" "<<c<<endl;
        int x;
        cin>>x;
        sol=min(sol,x);

        return x;
}

int go=1;

void solve(int r1,int c1,int r2,int c2)
{
        if (r1>r2 || c1>c2)
        {
                return;
        }
        if (r1==r2&&c1==c2)
        {
                ask(r1,c1);
                return;
        }
        int rm=(r1+r2)/2;
        vector<int> e;
        for (int j=max(go,c1);j<=c2;j++)
        {
                e.push_back(ask(rm,j));
        }
        int mn=e[0];
        for (auto &x : e)
                mn=min(mn,x);
        for (int j=c1;j<=c2;j++)
                if (e[j-c1]==mn)
                {
                        solve(r1,c1,rm-1,j);
                        go=max(go,j);
                        solve(rm+1,j,r2,c2);
                        return;
                }
}

int main()
{
        int n,m;
        cin>>n>>m;
        lim=4*(n+m);
        solve(1,1,n,m);
        cout<<"! "<<sol<<endl;
}