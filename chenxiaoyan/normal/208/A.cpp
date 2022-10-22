#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string now;
	cin>>now;
	int i;
	for(i=0;i<now.size();i++)
		if(now.substr(i,3)=="WUB")
		{
			now[i]=' ';
			if(i+1<now.size())
				now[i+1]=' ';
			if(i+2<now.size())
				now[i+2]=' ';
		}
	now=" "+now;
	for(i=1;i<now.size();i++)
	{
		if(now[i]!=' ')
			cout<<now[i];
		else if(now[i-1]!=' ')
			cout<<" ";
	}
	return 0;
}
/*1
WUBWUBABCWUB
*/
/*2
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
*/ 
/*3
WUBWUBIWUBAMWUBWUBX
*/