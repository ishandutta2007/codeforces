#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,h;
	int u1,d1,u2,d2;
	cin>>w>>h;
	cin>>u1>>d1;
	cin>>u2>>d2;
	int cur=w;
	for(int i=h;i>=0;i--)
	{
		cur+=i;
		if(i==d1)
			cur-=u1;
		if(i==d2)
			cur-=u2;
		cur=max(cur,0);
	}
	cout<<cur<<endl;
}