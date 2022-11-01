#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector a(n+1,vector(m+1,int(0)));
    vector<int> rows(n+2,0);
    vector<int> cols(m+2,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            rows[i]=max(rows[i],a[i][j]);
            cols[j]=max(cols[j],a[i][j]);
        }
    }
    sort(rows.begin()+1,rows.begin()+n+1,greater<>());
    sort(cols.begin()+1,cols.begin()+m+1,greater<>());
    int ridx=1;
    int cidx=1;
    vector b(n+2,vector(m+2,int(0)));
    vector<int> l(n+1,0);
    vector<int> r(n+1,0);
    auto add=[&](int i,int j,int c)
    {
        b[i][j]=c;
        if(l[i]==0||j<l[i]) l[i]=j;
        if(r[i]==0||r[i]<j) r[i]=j;
    };
    for(int x=n*m;x>=1;x--)
    {
        if(rows[ridx]==x&&cols[cidx]==x) add(ridx++,cidx++,x);
        else if(rows[ridx]==x)
        {
            int col=0;
            for(int j=1;j<cidx;j++) if(b[ridx-1][j]!=0&&col==0) col=j;
            add(ridx++,col,x);
        }
        else if(cols[cidx]==x)
        {
            int row=0;
            for(int i=1;i<ridx;i++) if(b[i][cidx-1]!=0&&row==0) row=i;
            add(row,cidx++,x);
        }
        else
        {
            int row=0,col=0;
            for(int i=1;i<ridx;i++)
            {
                if((b[i-1][l[i]-1]!=0||b[i+1][l[i]-1]!=0)&&row==0&&col==0) tie(row,col)=make_pair(i,l[i]-1);
                if((b[i-1][r[i]+1]!=0||b[i+1][r[i]+1]!=0)&&row==0&&col==0) tie(row,col)=make_pair(i,r[i]+1);
            }
            add(row,col,x);
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cout << b[i][j] << " \n"[j==m];
    return 0;
}