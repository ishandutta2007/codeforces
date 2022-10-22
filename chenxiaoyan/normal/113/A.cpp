#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string> wor;
string bac(string x,int len)
{
	if(x.size()<len)
		return "";
	return x.substr(x.size()-len,len);
}
int gen(string x)//1adj2adj3n4n5v6v,7
//error
{
	if(bac(x,4)=="lios")
		return 1;
	if(bac(x,5)=="liala")
		return 2;
	if(bac(x,3)=="etr")
		return 3;
	if(bac(x,4)=="etra")
		return 4;
	if(bac(x,6)=="initis")
		return 5;
	if(bac(x,6)=="inites")
		return 6;
	return 7;
}
bool ok()
{
	if(wor.size()==1)
		return gen(wor[0])!=7;
	int gender=gen(wor[0])%2,noofn=0;
	for(int i=0;i<wor.size();i++)
	{
		if(gen(wor[i])==3||gen(wor[i])==4)
			noofn++;
		if(gen(wor[i])==7||gen(wor[i])%2!=gender)
			return false;
		if(i)
			if(gen(wor[i])<gen(wor[i-1]))
				return false;
	}
	return noofn==1;
}
int main()
{
	string a,now="";
	getline(cin,a);
	a+=" ";
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==' ')
		{
			wor.push_back(now);
			now="";
		}
		else
			now+=a[i];
	}
	cout<<(ok()?"YES":"NO");
	return 0;
}
/*1
petr
*/
/*2
etis atis animatis etis atis amatis
*/
/*3
nataliala kataliala vetra feinites
*/