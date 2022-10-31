#include <iostream>
using namespace std;
int main()
{
	int n,a,b;
	int one,two,twoone;
	cin>>n>>a>>b;
	one=a;
	two=b;
	twoone=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if (x==2&&two>0){two--; continue; }
		if (x==1&&one>0){one--; continue; }
		else if (x==1&&two>0){two--; twoone++; continue; }
		else if (x==1&&twoone>0){twoone--; continue; }
		ans+=x;
	}
	cout<<ans<<endl;
	return 0;
}