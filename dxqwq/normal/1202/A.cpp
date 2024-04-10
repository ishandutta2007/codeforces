#include<bits/stdc++.h>
using namespace std;
string x,y;
int main()
{
	ios::sync_with_stdio(false);
	int T,ans,i,j,lx,ly;
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		i=0;
		j=0;
		lx=x.size();
		ly=y.size();
		while(1)
		{
			//cout<<i<<' '<<j<<' '<<x[lx-i-j-1]<<' '<<y[ly-i-1]<<endl;
			if(lx==j) 
			{
				cout<<j<<endl;
				break;
			}
			if(x[lx-i-j-1]==y[ly-i-1] && x[lx-i-j-1]=='1')
			{
				cout<<j<<endl;
				break;
			}
			if(x[lx-i-j-1]!=y[ly-i-1] && x[lx-i-j-1]=='0') 
			{
				j++;	
				continue;
			}
			if(y[ly-i-1]=='0')
			{
				i++;
				continue;
			}
		}
	}
	return 0;
}