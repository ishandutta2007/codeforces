#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
typedef long long ll;
using namespace std;
const ll mod1=998244353;
string radix(int num,int rad)
{
	if(num<rad)
	{
		char s='0'+num;
		string str="";
		str+=s;
		return str;
	} 
	char s='0'+num%rad;
	string str="";
	str+=s;
	return radix(num/rad,rad)+str;
}
int rad;
int main()
{
	cin>>rad;
	for(int i=1;i<rad;i++)
	{
		for(int j=1;j<rad;j++)
		cout<<radix(i*j,rad)<<' ';
		cout<<endl;
	}
	return 0;
}