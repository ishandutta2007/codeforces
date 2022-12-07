#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, k, an=0;
	cin>>n>>k;
	k=240-k;
	for(int a=0; a<n; a++)
	{
		if(k>=(a+1)*5)
		{
			k-=(a+1)*5, an++;
		}
		else break;
	}
	cout<<an;
	//system("PAUSE");
}