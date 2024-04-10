#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, m, ch=0;
	cin>>n>>m;
	int ar[n], q[m];
	for(int a=0; a<m; a++) q[a]=0;
	for(int a=0; a<n; a++)
	{
		int x;
		cin>>x;
		x--;
		if(x<m) q[x]++;
		ar[a]=x;
	}
	int mi=n/m;
	for(int a=0; a<m; a++)
	{
		//cout<<mi<<" ";
		while(q[a]<mi)
		{
			for(int b=0; b<n; b++)
			{
				if(ar[b]>=m)
				{
					ar[b]=a, q[a]++, ch++;
					break;
				}
				else
				{
					if(q[ar[b]]>mi)
					{
						//cout<<q[ar[b]]<<" ";
						q[ar[b]]--, ar[b]=a, q[a]++, ch++;
						break;
					}
				}
			}
		}
	}
	cout<<mi<<" "<<ch<<"\n";
	for(int a=0; a<n; a++) cout<<ar[a]+1<<" ";
}