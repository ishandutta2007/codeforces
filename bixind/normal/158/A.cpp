# include <iostream>

using namespace std;

int main () 
{
	int k,n,e,a,p = 0 ;
	cin>>n>>k;
	for (int i = 1; i<=n; i++)
	{
		cin>>a;
		if ((a > 0) && (i < k)) ++p;
		if (i == k) e = a;
		if ((i>=k) && (a>0) && (a == e)) ++p;
	}
	cout<<p;
	return 0;
}