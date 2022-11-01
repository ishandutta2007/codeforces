#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

struct point
{
	int x,y;

}m[123456],a[123456];
int main()
{
	int n; ll j;
	cin>>n>>j;
	cin>>m[0].x>>m[0].y;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=0;i<2*n;i++)
	{
		m[i+1].x = 2*a[i%n].x-m[i].x;
		m[i+1].y = 2*a[i%n].y-m[i].y; 
	}
	cout<<m[j%(2*n)].x<<" ";
	cout<<m[j%(2*n)].y<<endl;
	return 0;
}