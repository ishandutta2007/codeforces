#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, l=-1e9, r=1e9, inf=1e9, add=0, er=0;
	cin>>n;
	for(int a=0; a<n; a++)
	{
		int c, d;
		cin>>c>>d;
		if(d==2)
		{
			l=max(l, -inf), r=min(r, 1899-add);
		}
		else
		{
			l=max(l, 1900-add), r=min(r, inf);
		}
		if(r<l)
		{
			er=1;
			break;
		}
		add+=c;
	}
	if(er) cout<<"Impossible";
	else if(r==inf) cout<<"Infinity";
	else cout<<r+add;
	//system("pause");
}