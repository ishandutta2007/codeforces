#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
	map<string,int> no;
	string lon;
	cin>>lon;
	const int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i=0;i<lon.size();i++)
	{
		string tim=lon.substr(i,10);
		if(tim.size()<10)
			continue;
		if(tim[2]!='-'||tim[5]!='-'||tim[0]=='-'||tim[1]=='-'||tim[
		3]=='-'||tim[4]=='-'||tim[6]=='-'||tim[7]=='-'||tim[8]=='-'
		||tim[9]=='-')
			continue;
		string day=tim.substr(0,2),mon=tim.substr(3,2),yea=tim.
		substr(6,4);
		int dayno=(day[0]-'0')*10+day[1]-'0',monno=(mon[0]-'0')*10+
		mon[1]-'0';
		if(monno<1||monno>12)
			continue;
		if(dayno<1||dayno>md[monno]||yea<"2013"||yea>"2015")
			continue;
		no[tim]++;
	}
	int mx=-1;
	for(map<string,int>::iterator itr=no.begin();itr!=no.end();itr++
	)
		if(itr->second>mx)
		{
			lon=itr->first;
			mx=itr->second;
		}
	cout<<lon;
	return 0;
}
/*1
777-444---21-12-2013-12-2013-12-2013---444-777
*/