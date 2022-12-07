#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int n, c, pr=0, q=0;
	cin>>n>>c;
	for(int a=0; a<n; a++)
	{
		int x;
		cin>>x;
		if((x-pr)>c) q=0;
		q++, pr=x;
	}
	cout<<q;
}