#include<iostream>
using namespace std;
int main()
{
	string cur;
	cin>>cur;
	string my[5];
	bool ok=0;
	for(int i=0;i<5;i++)
	{
		cin>>my[i];
		if(my[i][0]==cur[0]||my[i][1]==cur[1]) ok=1;
	}
	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}