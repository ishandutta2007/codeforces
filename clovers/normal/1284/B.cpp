#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200001;

ll n,l[N],t[N];
vector<int> a[N];
vector<pair<int,int> > v;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];j++)
		{
			int x; scanf("%d",&x);
			a[i].push_back(x);
		}
		int bl=1;
		for(int j=1;j<l[i];j++) if(a[i][j]>a[i][j-1]) bl=0;
		if(bl) v.push_back(make_pair(a[i][0],a[i][l[i]-1]));
	}
	for(int i=0;i<(int)v.size();i++) t[i]=v[i].second;
	sort(t,t+(int)v.size());
	ll sum=0;
	for(int i=0;i<(int)v.size();i++)
	{
		int pos=lower_bound(t,t+(int)v.size(),v[i].first)-t;
		sum+=(int)v.size()-pos;
	}
	cout<<n*n-sum<<endl;
}