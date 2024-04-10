#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string ins(string a,int b,char c) 
{
	string d=a.substr(0,b);
	string e=a.substr(b,a.size()-b);
	string f=d+c+e;
	return f;
}
string del(string a,int b)
{
	string d=a.substr(0,b);
	string e=a.substr(b+1,a.size()-b-1);
	string f=d+e;
	return f;
}
string shankongge(string q)
{
	string e=q;
	for(;;)
	{
		if(e.find("  ")!=4294967295)//18446744073709551615
		e=del(e,e.find("  "));
		else if(e.find(" ,")!=4294967295)//18446744073709551615
		e=del(e,e.find(" ,"));
		else if(e.find(" !")!=4294967295)//18446744073709551615
		e=del(e,e.find(" !"));
		else if(e.find(" .")!=4294967295)//18446744073709551615
		e=del(e,e.find(" ."));
		else if(e.find(" ?")!=4294967295)//18446744073709551615
		e=del(e,e.find(" ?"));
		else
		break;
	}
	return e;
}
int main()
{
	string a;
	getline(cin,a);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==','||a[i]=='?'||a[i]=='!'||a[i]=='.')
		a=ins(a,1+i,' ');
	}
	a=shankongge(a);
	cout<<a;
	return 0;
}