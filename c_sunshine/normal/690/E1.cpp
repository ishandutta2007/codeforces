#include<cstdio>
#include<cstring>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#include<vector>
int n,m;
int a[333][333];

vector<int> V;

int ABS(int x){return x<0?-x:x;}

double calc()
{
	sort(V.begin(),V.end());
	int l=V.size();
	double s1=0,s2=0;
	for(int i=l/10;i+l/10<V.size();i++)
		s1+=V[i],s2+=1;
	return s1/s2;
}

int main()
{
	//freopen("sample.in","r",stdin);
	//freopen("sample.txt","w",stdout);
	int Q;
	cin>>Q;
	while(Q--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",a[i]+j);
		double s1,s2;
		V.clear();
		for(int j=1;j<=m;j++)
			V.push_back(ABS(a[n/2][j]-a[n/2+1][j]));
		s1=calc();
		V.clear();
		for(int j=1;j<=m;j++)
			V.push_back(ABS(a[1][j]-a[n][j]));
		s2=calc();
		double ss=s1/s2;
		if(ss>1)cout<<"YES";
		else cout<<"NO";
		//cout<<' '<<ss;
		cout<<endl;
	}
	return 0;
}