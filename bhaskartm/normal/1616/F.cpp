#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int c[5000];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		static int A[70][70];memset(A,-1,sizeof A);
		int n,m,i,j,k,l,x,y,z;
		cin>>n>>m;
		for (i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if (x>y) swap(x,y);
			A[x][y]=i;
			c[i]=z;
		}
		vector<vector<int>> a;
		for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) if (~(x=A[i][j])) for (k=j+1;k<=n;k++) if (~(y=A[j][k])&&~(z=A[i][k]))
		{
			vector<int> v(m+1);
			v[x]=v[y]=v[z]=1;
			a.push_back(v);
		}
		for (i=0;i<m;i++) if (c[i]!=-1)
		{
			vector<int> v(m+1);
			v[i]=1;v[m]=c[i]%3;
			a.push_back(v);
		} else c[i]=0;
		n=a.size();
		for (i=0;i<n;i++)
		{
			for (j=0;j<=m;j++) if (a[i][j]) break;
			if (j==m+1)
			{
				swap(a[i],a.back());
				a.pop_back();--n;--i;
				continue;
			}
			if (j==m) goto no;
			if (a[i][j]==2) for (int &x:a[i]) x=(3-x)%3;
			for (k=0;k<n;k++) if (k!=i&&a[k][j])
			{
				int r=3-a[k][j];
				for (l=0;l<=m;l++) a[k][l]=(a[k][l]+a[i][l]*r)%3;
			}
		}
		for (i=0;i<n;i++) for (j=0;j<m;j++) if (a[i][j]) {c[j]=a[i][m];break;}
		for (i=0;i<m;i++) cout<<(c[i]?c[i]:3)<<" \n"[i==m-1];
		continue;
		no:cout<<"-1\n";
	}
}