/**
 *
 * Jur Solemn ca raman la acest stil toata aceasta saptamana.
 *
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+7;
int n,m,v[N][N];

int a[N][N];
int b[N][N];
int c[N][N];
int d[N][N];

struct kek
{
        int i;
        int x;
};

bool operator < (kek a,kek b)
{
        return a.x<b.x;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        cin>>v[i][j];
                }
        }
        for(int i=1;i<=n;i++)
        {
                vector<kek>ord;
                for(int j=1;j<=m;j++)
                {
                        ord.push_back({j,v[i][j]});
                }
                sort(ord.begin(),ord.end());
                int last=-1,cur=0;
                for(auto &it:ord)
                {
                        int j=it.i;
                        int x=it.x;
                        cur+=(x!=last); last=x;
                        a[i][j]=cur-1;
                }
                last=-1;
                cur=0;
                reverse(ord.begin(),ord.end());
                for(auto &it:ord)
                {
                        int j=it.i;
                        int x=it.x;
                        cur+=(x!=last); last=x;
                        b[i][j]=cur-1;
                }
        }
        for(int j=1;j<=m;j++)
        {
                vector<kek>ord;
                for(int i=1;i<=n;i++)
                {
                        ord.push_back({i,v[i][j]});
                }
                sort(ord.begin(),ord.end());
                int last=-1,cur=0;
                for(auto &it:ord)
                {
                        int i=it.i;
                        int x=it.x;
                        cur+=(x!=last); last=x;
                        c[i][j]=cur-1;
                }
                last=-1;
                cur=0;
                reverse(ord.begin(),ord.end());
                for(auto &it:ord)
                {
                        int i=it.i;
                        int x=it.x;
                        cur+=(x!=last); last=x;
                        d[i][j]=cur-1;
                }
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        cout<<max(a[i][j],c[i][j])+max(b[i][j],d[i][j])+1<<" ";
                }
                cout<<"\n";
        }
        return 0;
}