#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	int n, pos=0;
	cin>>n;
	int ar[n];
	for(int a=0; a<n; a++)
	{
		cin>>ar[a];
		if(ar[a]!=0) pos=1;
	}
	if(pos)
	{
		vector <int*> an;
		int yk=0;
		while(yk<n)
		{
			if(ar[yk]!=0)
			{
				an.push_back(new int[2]);
				an.back()[0]=yk+1;
				yk++;
				while(yk<n)
				{
					if(ar[yk]==0) yk++;
					else break;
				}
				an.back()[1]=yk;
			}
			else yk++;
		}
		an[0][0]=1;
		cout<<"YES"<<"\n"<<an.size()<<"\n";
		for(int a=0; a<an.size(); a++) cout<<an[a][0]<<" "<<an[a][1]<<"\n";
	}
	else cout<<"NO";
}