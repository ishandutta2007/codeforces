#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, su=0, ma=0;
	cin>>n;
	for(int a=0; a<n; a++)
	{
		int x;
		cin>>x;
		ma=max(x, ma);
		su+=x;
	}
	cout<<ma*n-su;
}