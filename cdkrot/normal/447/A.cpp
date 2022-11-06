#include <iostream>
#include <stdint.h>
#include <vector>

using std::cin; using std::cout; using std::endl;

int main()
{
	int p, n; cin>>p>>n;
	std::vector<char> t; t.resize(p);
	for (int i=1; i<=n; i++)
	{
		int X; cin>>X;
		if (t[X % p]==1)
		{
			cout<<i<<endl;
			return 0;
		}
		t[X % p]=1;
	}
	
	cout<<"-1\n";
	
	return 0;
}