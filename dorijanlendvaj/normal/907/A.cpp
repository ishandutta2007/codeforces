#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;
int c1,c2,c3;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b>>c>>d;
	if (d>2*c)
	{
		cout<<-1<<endl;
		return 0;
	}
	c1=a*2;
	c2=b*2;
	c3=max(c,d);
	if (d<=c3 && d*2>=c3 && d*2<c2 && d*2<c1) cout<<c1<<endl<<c2<<endl<<c3<<endl;
	else cout<<-1<<endl;
}