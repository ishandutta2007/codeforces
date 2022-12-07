#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, k;
	cin>>n>>k;
	int ar[n], su=0;
	for(int a=0; a<n; a++) cin>>ar[a];
	for(int a=0; a<(n-1); a++)
	{
		if(ar[a]+ar[a+1]<k)
		{
			su+=k-(ar[a]+ar[a+1]);
			ar[a+1]+=k-(ar[a]+ar[a+1]);
		}
	}
	cout<<su<<"\n";
	for(int a=0; a<n; a++) cout<<ar[a]<<" ";
}