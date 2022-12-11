# include <iostream>

using namespace std;

int main () 
{
	long long int w;
	cin>>w;
	if (w == 2) w = 1;
	if (w % 2 == 0) cout<<"YES"; else cout<<"NO";
	return 0;
}