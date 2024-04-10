#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+7;
int n, m, a[N][N], per[N], pec[N], cox[N];
vector<pair<int, int>> cells;

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n>>m;
        for (int i=1; i<=n; i++)
        {
                string s;
                cin>>s;
                for (int j=1; j<=m; j++)
                {
                        if (s[j-1]=='X')
                        {
                                per[i]=j;
                                pec[j]=i;
                        }
                        else
                        {
                                cells.push_back({i, j});
                        }
                }
        }


        ll sol=0;
        for (int it=0; it<2; it++)
        {
                for (auto &x : cells) cox[x.first]++;
                for (int i=0; i<N; i++)
                {
                        for (int j=0; j<N; j++)
                        {
                                sol+=(ll) abs(i-j) * cox[i]*cox[j];
                        }
                }
                for (auto &x : cells) swap(x.first, x.second);
                for (int  i=1; i<=n; i++) cox[i]=0;
        }


        { /// zid de r

                { /// zid de r crescator
                        int i=1;
                        while (i<=n)
                        {
                                if (!per[i])
                                {
                                        i++;
                                        continue;
                                }
                                int j=i;
                                while (j+1<=n && per[j+1]!=0 && per[j+1]>per[j]) j++;

                                vector<pair<int, int>> mowgli;
                                for (int k=i; k<=j; k++)
                                {
                                        mowgli.push_back({per[k]-1, m-per[k]});
                                }

                                {
                                        for (int x=0; x<(int) mowgli.size(); x++)
                                        {
                                                for (int y=x; y<(int) mowgli.size(); y++)
                                                {
                                                        sol+=4*mowgli[x].first*mowgli[y].second;
                                                }
                                        }
                                }

                                i=j+1;
                        }
                }
                { /// zid de r descrescator
                        int i=1;
                        while (i<=n)
                        {
                                if (!per[i])
                                {
                                        i++;
                                        continue;
                                }
                                int j=i;
                                while (j+1<=n && per[j+1]!=0 && per[j+1]<per[j]) j++;

                                vector<pair<int, int>> mowgli;
                                for (int k=i; k<=j; k++)
                                {
                                        mowgli.push_back({per[k]-1, m-per[k]});
                                }

                                {
                                        for (int x=0; x<(int) mowgli.size(); x++)
                                        {
                                                for (int y=0; y<x; y++)
                                                {
                                                        sol+=4*mowgli[x].first*mowgli[y].second;
                                                }
                                        }
                                }

                                i=j+1;
                        }
                }

        }


        swap(n, m);
        for (int i=1; i<=n; i++)
                per[i]=pec[i];

        { /// zid de c

                { /// zid de c crescator
                        int i=1;
                        while (i<=n)
                        {
                                if (!pec[i])
                                {
                                        i++;
                                        continue;
                                }
                                int j=i;
                                while (j+1<=n && per[j+1]!=0 && per[j+1]>per[j]) j++;

                                vector<pair<int, int>> mowgli;
                                for (int k=i; k<=j; k++)
                                {
                                        mowgli.push_back({per[k]-1, m-per[k]});
                                }

                                {
                                        for (int x=0; x<(int) mowgli.size(); x++)
                                        {
                                                for (int y=x; y<(int) mowgli.size(); y++)
                                                {
                                                        sol+=4*mowgli[x].first*mowgli[y].second;
                                                }
                                        }
                                }

                                i=j+1;
                        }
                }
                { /// zid de c descrescator
                        int i=1;
                        while (i<=n)
                        {
                                if (!per[i])
                                {
                                        i++;
                                        continue;
                                }
                                int j=i;
                                while (j+1<=n && per[j+1]!=0 && per[j+1]<per[j]) j++;

                                vector<pair<int, int>> mowgli;
                                for (int k=i; k<=j; k++)
                                {
                                        mowgli.push_back({per[k]-1, m-per[k]});
                                }

                                {
                                        for (int x=0; x<(int) mowgli.size(); x++)
                                        {
                                                for (int y=0; y<x; y++)
                                                {
                                                        sol+=4*mowgli[x].first*mowgli[y].second;
                                                }
                                        }
                                }

                                i=j+1;
                        }
                }

        }

        cout<<fixed<<setprecision(10)<<(ld) (sol)/((ld) cells.size()*cells.size())<<"\n";



        return 0;
}