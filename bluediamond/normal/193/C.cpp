#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N=10;
int n;
int m;
ld a[N][N];
ld ans[N];
bool ok;

void algo()
{
        ok=1;
        int i=1,j=1;
        while (i<=n && j<=n)
        {
                int k=i;
                while (a[k][j]==0 && k+1<=n)
                {
                        k++;
                }
                if (a[k][j]==0)
                {
                        j++;
                        continue;
                }
                for (int it=j;it<=n+1;it++)
                        swap(a[i][it],a[k][it]);
                ld dv=a[i][j];
                for (int it=j;it<=n+1;it++)
                        a[i][it]/=dv;
                for (int k=i+1;k<=n;k++)
                {
                        ld x=-a[k][j];
                        for (int it=j;it<=n+1;it++)
                                a[k][it]+=x*a[i][it];
                }
                i++;
                j++;
        }
        for (int i=n;i>=1;i--)
        {
                int j=1;
                while (a[i][j]==0 && j+1<=n)
                {
                        j++;
                }
                if (fabs(a[i][j])<=1e-14 && fabs(a[i][n+1])>1e-14)
                {
                        ok=0;
                        return;
                }
                ans[j]=a[i][n+1];
                for (int it=j+1;it<=n;it++)
                        ans[j]-=ans[it]*a[i][it];
        }
}

vector<vector<int>> kek;

void compute(int mask)
{
        vector<int> bits(4);
        for (int i=0;i<4;i++)
                if (mask&(1<<i))
                        bits[i]=1;
                else
                        bits[i]=0;
        vector<int> sol;
        for (int i=0;i<4;i++)
                for (int j=i+1;j<4;j++)
                        sol.push_back(bits[i]^bits[j]);
        kek.push_back(sol);
        return;
        for (auto &x : sol)
                cout<<x;
        cout<<"\n";
}

vector<int> sool={-1};
bool first=1;

void upd(int x0)
{
        vector<int> xs={x0};
        for (int i=1;i<=6;i++)
        {
                int pint=ans[i];
                ld dif=ans[i]-(ld)pint;
                if (fabs(dif)>1e-14)
                        return;
                xs.push_back(ans[i]);
        }
        for (auto &x : xs)
                if (x<0)
                        return;
        if (!ok)
                return;
        if (first)
        {
                first=0;
                sool=xs;
        }
        else
        {
                int sum_sol=0;
                for (auto &it : sool) sum_sol+=it;
                int sum_xs=0;
                for (auto &it : xs) sum_xs+=it;
                if (sum_xs<sum_sol)
                        sool=xs;
        }
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        for (int mask=1;mask<(1<<3);mask++)
                compute(mask);
        vector<int> b(6);
        for (int i=0;i<6;i++)
                cin>>b[i];
        int mx=0;
        for (auto &x : b)
                mx=max(mx,x);
        n=6;
        for (int x0=0;x0<=mx;x0++)
        {
                for (int eq=1;eq<=6;eq++)
                {
                        for (int co=1;co<=6;co++)
                                a[eq][co]=kek[co][eq-1];
                        a[eq][7]=b[eq-1]-x0*kek[0][eq-1];
                }
                algo();
                upd(x0);
        }
        if (first)
        {
                cout<<"-1\n";
                return 0;
        }
        else
        {
                int tits=0;
                for (auto &x : sool)
                        tits+=x;
                cout<<tits<<"\n";
                string sol[4];
                sol[0]=sol[1]=sol[2]=sol[3]="";
                for (int i=1;i<=tits;i++)
                        sol[3]+="a";
                for (int i=1;i<=7;i++)
                {
                        for (int j=1;j<=sool[i-1];j++)
                        {
                                for (int k=0;k<3;k++)
                                        if (i&(1<<k))
                                                sol[k]+="b";
                                        else
                                                sol[k]+="a";
                        }
                }
                cout<<sol[0]<<"\n";
                cout<<sol[1]<<"\n";
                cout<<sol[2]<<"\n";
                cout<<sol[3]<<"\n";
        }

}