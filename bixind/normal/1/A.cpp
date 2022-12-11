# include <iostream>

using namespace std;

int main () 
{
	long long int m,n,a,k,x,y;
	cin>>n>>m>>a;
	x = n/a;
	y = m/a;
	if (m % a != 0) ++y;
	if (n % a != 0) ++x;
	k = x * y;
	cout<<k;
	return 0;
}