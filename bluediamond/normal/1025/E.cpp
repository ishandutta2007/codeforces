#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T
{
        int a,b,c,d;
};

const int N=50+7;
int n;
int tp[N][N];
vector<T> sol;

void p2(int r,int c)
{
        if (tp[r][c+1])
        {
                p2(r,c+1);
        }
        sol.push_back({r,c,r,c+1});
        swap(tp[r][c],tp[r][c+1]);
}

void p1(int i,int col)
{
        bool all=1;
        for (int k=col+1;k<=n;k++)
                if (tp[i][k]==0)
                        all=0;
        if (all==0)
        {
                p2(i,col);
                return;
        }
        p1(i+1,col);
        sol.push_back({i,col,i+1,col});
        swap(tp[i][col],tp[i+1][col]);
}

void print()
{
        return;
        for (int i=1;i<=n;i++)
        {
                for (int j=1;j<=n;j++)
                {
                        cout<<tp[i][j]<<" ";
                }
                cout<<"\n";
        }
        cout<<"--------\n";
}

void p3(int r,int c)
{
        if (tp[r][c-1])
        {
                p3(r,c-1);
        }
        sol.push_back({r,c,r,c-1});
        swap(tp[r][c],tp[r][c-1]);
}

vector<T> maga(vector<pair<int,int>> e)
{
        sol.clear();
        for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) tp[i][j]=0;
        int m=0;
        for (auto &it : e)
                tp[it.first][it.second]=++m;
        print();
        /// toate sa aiba coloane distincte
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
                int init=cnt;
                while (1)
                {
                        bool oke=1;
                        cnt=init;
                        for (int j=1;j<=n;j++)
                                if (tp[i][j])
                                {
                                        cnt++;
                                        if (j==cnt)
                                                continue;
                                        oke=0;
                                        if (j>cnt)
                                        {
                                                p3(i,j);
                                        }
                                        else
                                        {
                                                p2(i,j);
                                        }
                                        break;
                                }
                        if (oke)
                                break;
                }
        }
        for (int col=1;col<=n;col++)
        {
                int last=-1;
                while (1)
                {

                        int cnt=0;
                        for (int i=1;i<=n;i++)
                                cnt+=(tp[i][col]>0);
                        if (last!=-1&&last==cnt)
                        {
                                cout<<"oh hold up\n";
                                exit(0);
                        }
                        last=cnt;
                        if (cnt<=1)
                                break;
                        for (int i=1;i<=n;i++)
                                if (tp[i][col])
                                {
                                        p1(i,col);
                                        break;
                                }
                }
        }
        print();
        set<int> rows;
        for (int j=1;j<=m;j++)
        {
                for (int i=1;i<=n;i++)
                {
                        if (tp[i][j])
                        {
                                if (rows.count(i)==0)
                                {
                                        rows.insert(i);
                                        continue;
                                }
                                bool found=0;
                                for (int r=i+1;r<=n;r++)
                                {
                                        if (rows.count(r)==0)
                                        {
                                                while (i<r)
                                                {
                                                        sol.push_back({i,j,i+1,j});
                                                        swap(tp[i][j],tp[i+1][j]);
                                                        i++;
                                                }
                                                rows.insert(r);
                                                found=1;
                                                break;
                                        }
                                }
                                if (found)
                                        continue;
                                for (int r=i-1;r>=1;r--)
                                {
                                        if (rows.count(r)==0)
                                        {
                                                while (i>r)
                                                {
                                                        sol.push_back({i,j,i-1,j});
                                                        swap(tp[i][j],tp[i-1][j]);
                                                        i--;
                                                }
                                                rows.insert(r);
                                                found=1;
                                                break;
                                        }
                                }
                        }
                }
        }
        /**for (int i=1;i<=n;i++)
        {
                for (int j=1;j<=n;j++)
                {
                        cout<<tp[i][j]<<" ";
                }
                cout<<"\n";
        }
        cout<<"--------\n";
        **/
        for (int i=1;i<=n;i++)
        {
                for (int j=1;j<=n;j++)
                        if (tp[i][j]&&j<tp[i][j])
                        {
                                sol.push_back({i,j,i,j+1});
                                swap(tp[i][j],tp[i][j+1]);
                        }
                for (int j=n;j>=1;j--)
                        if (tp[i][j]&&j>tp[i][j])
                        {
                                sol.push_back({i,j,i,j-1});
                                swap(tp[i][j],tp[i][j-1]);
                        }
        }
        for (int i=n;i>=2;i--)
        {
                for (int j=1;j<=m;j++)
                        if (tp[i][j])
                        {
                                sol.push_back({i,j,i-1,j});
                                swap(tp[i][j],tp[i-1][j]);
                        }
        }
        return sol;
}

void print(vector<T> v)
{
        cout<<(int)v.size()<<"\n";
        for (auto &it : v)
                cout<<it.a<<" "<<it.b<<" "<<it.c<<" "<<it.d<<"\n";
}

int m;
int r1[N],c1[N],r2[N],c2[N];



int main()
{
        ios::sync_with_stdio(0);cin.tie(0);


        cin>>n>>m;
        for (int i=1;i<=m;i++) cin>>r1[i]>>c1[i];
        for (int i=1;i<=m;i++) cin>>r2[i]>>c2[i];

        vector<pair<int,int>> f,s;
        for (int i=1;i<=m;i++)
                f.push_back(make_pair(r1[i],c1[i])),
                s.push_back(make_pair(r2[i],c2[i]));


        vector<T> x=maga(f),y=maga(s);
        reverse(y.begin(),y.end());
        for (auto &it : y)
        {
                x.push_back({it.c,it.d,it.a,it.b});
        }
        print(x);
}