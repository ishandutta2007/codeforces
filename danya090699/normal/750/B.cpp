#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, cu=0, er=0;
	cin>>n;
	for(int a=0; a<n; a++)
	{
		int x;
		string s;
		cin>>x>>s;
		if(cu==0 and s!="South") er=1;
		if(cu==20000 and s!="North") er=1; 
		if(s=="North") cu-=x;
		else if(s=="South") cu+=x;
		if(cu<0 or cu>20000)
		{
			er=1;
			break;
		}
	}
	if(cu!=0) er=1;
	if(er) cout<<"NO";
	else cout<<"YES";
	//system("pause");
}