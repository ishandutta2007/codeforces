//  228

#include<bits/stdc++.h>
using namespace std;

int p[105][105];
int a[105],ll,lr,sum=99999999;
int main()
{
    int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>ll>>lr;
		p[ll][lr]=1;
		p[lr][ll]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=j;k<=n;k++)
				if(p[i][j]==1&&p[j][k]==1&&p[i][k]==1)
					sum=min(sum,a[i]+a[j]+a[k]);
	if(sum==99999999) cout<<"-1"<<endl;
	else cout<<sum<<endl;
	return 0;
}
//