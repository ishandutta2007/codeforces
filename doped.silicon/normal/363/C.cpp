#include <bits/stdc++.h>
using namespace std;

int main() {
	char x,y='8',z='7',w='2';
	while(cin>>x)
	{
		if(!((x==y&&y==z)||(x==y&&z==w)))
		{
			cout<<x;
			w=z;
			z=y;
			y=x;
		}
	}
	
	return 0;
}