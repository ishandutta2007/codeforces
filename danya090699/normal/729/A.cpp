#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	string s;
	int n, yk=0;
	cin>>n>>s;
	while(yk<n)
	{
		if(s[yk]=='o')
		{
			int q=1;
			yk++;
			while(yk<n)
			{
				if(((s[yk]=='g')and(s[yk-1]=='o'))or((s[yk]=='o')and(s[yk-1]=='g')))
				{
					yk++, q++;
				}
				else break;
			}
			if(q<3)
			{
				yk-=q-1;
				cout<<s[yk-1];
			}
			else
			{
				if(q%2==0) yk--;
				cout<<"***";
			}
		}
		else
		{
			cout<<s[yk];
			yk++;
		}
	}
}