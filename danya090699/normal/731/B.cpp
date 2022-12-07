#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n, pos=1;
	cin>>n;
	int ar[n];
	for(int a=0; a<n; a++) cin>>ar[a];
	for(int a=0; a<n; a++)
	{
		if(ar[a]%2==1)
		{
			if(a+1<n)
			{
				if(ar[a+1]!=0)
				{
					ar[a+1]--;
				}
				else
				{
					pos=0;
					break;
				}
			}
			else
			{
				pos=0;
				break;
			}
		}
	}
	if(pos) cout<<"YES";
	else cout<<"NO";
}