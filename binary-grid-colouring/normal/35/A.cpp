#include<bits/stdc++.h>
using namespace std;
int n;
bool v[5];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	v[n] = true;
	for(int i=1;i<=3;i++)
	{
		int a,b;
		cin>>a>>b;
		swap(v[a],v[b]); 
	}
	for(int i=1;i<=3;i++)
	{
		if(v[i]==true)
		{
			cout<<i<<endl;
		}
	}
	return 0;
 }