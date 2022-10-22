#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
bool yes(string x)
{
	string cpy=x;
	reverse(x.begin(),x.end());
	return x==cpy;
}
bool can[10];
int main()
{
	vector<string> ans;
	int n,i,nee=0,hav[256];
	cin>>n;
	bool ok[256];
	for(i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		can[x]=true;
		nee|=1<<x;
	}
	if(n>6)
	{
		cout<<0;
		return 0;
	}
	for(i=0;i<10;i++)
	{
		ok[i]=can[i];
		hav[i]=1<<i;
	}
	for(i=10;i<100;i++)
	{
		ok[i]=can[i%10]&&can[i/10];
		hav[i]=1<<i%10|1<<i/10;
	}
	for(i=100;i<256;i++)
	{
		ok[i]=can[i%10]&&can[i/10%10]&&can[i/100];
		hav[i]=1<<i%10|1<<i/10%10|1<<i/100;
	}
	for(i=0;i<256;i++)
	{
		if(!ok[i])
			continue;
		for(int j=0;j<256;j++)
		{
			if(!ok[j])
				continue;
			for(int k=0;k<256;k++)
			{
				if(!ok[k]||(hav[i]|hav[j]|hav[k])!=nee)
					continue;
				char _[16],_0[16];
				string ip,reaip,spa="";
				sprintf(_,"%d%d%d",i,j,k);
				sprintf(_0,"%d.%d.%d.",i,j,k);
				ip=_;
				reaip=_0;
				if(yes(ip+ip[0]))
					ans.push_back(reaip+ip[0]);
				if(ip[1]!='0'&&yes(ip+ip[1]+ip[0]))
					ans.push_back(reaip+ip[1]+ip[0]);
				
				if(ip[2]!='0'&&spa+ip[2]+ip[1]+ip[0]<"256"&&yes(ip+ip[2]
				+ip[1]+ip[0]))
					ans.push_back(reaip+ip[2]+ip[1]+ip[0]);
			}
		}
	}
	cout<<ans.size();
	for(i=0;i<ans.size();i++)
		cout<<"\n"<<ans[i];
	return 0;
}
/*1
6
0 1 2 9 8 7
*/
/*2
1
4
*/