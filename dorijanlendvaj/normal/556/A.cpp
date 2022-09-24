#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
char a;
int nula;
int jedan;

int main()
{
	cin>>n;
	for (int i=0;i<n;++i)
	{
		cin>>a;
		if (a=='0') ++nula;
		else ++jedan;
	}
	cout<<n-(min(nula,jedan)*2)<<endl;
}