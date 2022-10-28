#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
int a[200005],b[200005];
void func(int i)
{
	vector<int> v;
	int count=0;
	int k=i+1;
	i=a[i];
	while(i!=k)
	{
		v.pb(i);
		i=a[i-1];
		count++;
	}
	count++;
	b[k-1]=count;
	for(auto i:v)
	{
		b[i-1]=count;
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,i,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++)
		{
			if(b[i]==0)
				func(i);
		}
		for(i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<"\n";
	}
	return 0;
}