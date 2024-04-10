#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
map<string,int> a;
int s;
void f()
{
	string st="";
	char ch;ch=getchar();
	while (ch>='A'&&ch<='Z') 
	{
	 	  st.push_back(ch);
	 	  ch=getchar();
	 }
	//cout<<st<<endl;
	s+=a[st];
	a[st]++;
	while (ch==','||ch==':') {f();ch=getchar();}
	a[st]--;
}
int main()
{
	f();
	cout<<s;
	return 0;
}