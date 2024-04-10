#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
bool hav[1001];
int main()
{
	vector<vector<int> > list;
	vector<int> now;
	int i,now0=0;
	string see;
	cin>>see;
	see+=",";
	for(i=0;i<see.size();i++)
		if(see[i]==',')
		{
			hav[now0]=true;
			now0=0;
		}
		else
			now0=now0*10+see[i]-'0';
	for(i=1;i<=1001;i++)
		if(hav[i])
			now.push_back(i);
		else
		{
			list.push_back(now);
			now.clear();
		}
	string ans;
	for(i=0;i<list.size();i++)
	{
		if(!list[i].size())
			continue;
		char now1[1001];
		if(list[i].size()==1)
			sprintf(now1,"%d,",list[i][0]);
		else
			sprintf(now1,"%d-%d,",list[i][0],list[i][list[i].size()-1]);
		ans+=now1;
	}
	cout<<ans.substr(0,ans.size()-1);
	return 0;
}
/*1
1,2,3,1,1,2,6,6,2
*/
/*2
3,2,1
*/
/*3
30,20,10
*/