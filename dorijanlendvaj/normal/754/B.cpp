#include <bits/stdc++.h>

using namespace std;

string arr[11];

int main()
{
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	for (int i=0;i<4;++i)
	{
		for (int j=0;j<4;++j)
		{
			if (arr[i][j]=='.')
			{
				arr[i][j]='x';
				for (int k=0;k<4;++k)
				{
					if (arr[k].substr(0,3)=="xxx" || arr[k].substr(1,3)=="xxx")
					{
						cout<<"YES"<<endl;
						return 0;
					}
				}
				for (int k=0;k<4;++k)
				{
					if (arr[1][k]=='x' && arr[2][k]=='x')
					{
						if (arr[0][k]=='x' || arr[3][k]=='x')
						{
							cout<<"YES"<<endl;
							return 0;
						}
					}
				}
				if (arr[1][1]=='x' && arr[2][2]=='x')
				{
					if (arr[0][0]=='x' || arr[3][3]=='x')
					{
						cout<<"YES"<<endl;
						return 0;
					}
				}
				if (arr[1][2]=='x' && arr[2][1]=='x')
				{
					if (arr[0][3]=='x' || arr[3][0]=='x')
					{
						cout<<"YES"<<endl;
						return 0;
					}
				}
				if (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[1][1]=='x')
				{
					cout<<"YES"<<endl;
					return 0;
				}
				if (arr[1][3]==arr[2][2] && arr[2][2]==arr[3][1] && arr[2][2]=='x')
				{
					cout<<"YES"<<endl;
					return 0;
				}
				if (arr[0][1]==arr[1][2] && arr[1][2]==arr[2][3] && arr[1][2]=='x')
				{
					cout<<"YES"<<endl;
					return 0;
				}
				if (arr[1][0]==arr[2][1] && arr[2][1]==arr[3][2] && arr[2][1]=='x')
				{
					cout<<"YES"<<endl;
					return 0;
				}
				arr[i][j]='.';
			}
		}
	}
	cout<<"NO"<<endl;
}