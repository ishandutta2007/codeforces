#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,flag,pd[110];
string s,all;
void calc(string q)
{
	cout<<"? "<<q<<endl;
	fflush(stdout);
	int K=read(),len=q.length();
	if(K==-1) exit(0);
	for(int i=1;i<=K;++i)
	{
		flag=1;
		int st=read()-1;
		for(int j=0;j<len;++j) s[st+j]=q[j],pd[st+j]=1;
	}
}
void sbsolve()
{
	calc("CC");
	calc("CH");
	calc("CO");
	calc("HO");
	calc("OO");
	for(int i=1;i<n-1;++i) if(!pd[i]) s[i]='H',pd[i]=1;
	all=s;
	if(pd[0] && pd[n-1]) return;
	if(pd[0])
	{
		all[n-1]='C';
		calc(all);
		all[n-1]='H';
		calc(all);
		return;
	}
	if(pd[n-1])
	{
		all[0]='H';
		calc(all);
		all[0]='O';
		calc(all);
		return;
	}
	all[0]='H',all[n-1]='C';
	calc(all);
	if(pd[0] && pd[n-1]) return;
	all[0]='H',all[n-1]='H';
	calc(all);
	if(pd[0] && pd[n-1]) return;
	all[0]='O',all[n-1]='C';
	calc(all);
	if(pd[0] && pd[n-1]) return;
	s[0]='O',s[n-1]='H';
}
char cc[10]="HOC";
void fun(int lim)
{
	int num=0;
	all=s;
	for(int i=0;i<3;++i) if((pd[0] && cc[i]==s[0]) || (!pd[0] && i<2))
		for(int j=0;j<3;++j) if((pd[1] && cc[j]==s[1]) || (!pd[1] && j<2))
			for(int k=0;k<3;++k) if((pd[2] && cc[k]==s[2]) || (!pd[2] && k<2))
				for(int w=0;w<3;++w) if((pd[3] && cc[w]==s[3]) || !pd[3])
				{
					++num;
					all[0]=cc[i];
					all[1]=cc[j];
					all[2]=cc[k];
					all[3]=cc[w];
					if(num==lim) {s=all;return;}
					calc(all);
				}
}
void spsolve()
{
	calc("CC");
	calc("CH");
	calc("CO");
	calc("HO");
	if(flag) {fun(6);return;}
	calc("OO");
	if(flag)
	{
		if(!pd[1]) s[1]='H',pd[1]=1;
		if(!pd[2]) s[2]='H',pd[2]=1;
		if(!pd[0] && !pd[3]) s[0]='H',pd[0]=1;
		fun(3);
		return;
	}
	s[1]=s[2]='H';
	pd[1]=pd[2]=1;
	calc("HHH");
	if(flag)
	{
		if(pd[0] && pd[3]) return;
		if(pd[0]) s="HHHC";
		else s="OHHH";
		return;
	}
	s="OHHC";
}
int main()
{
	T=read();
	while(T--)
	{
		memset(pd,0,sizeof(pd));
		n=read();
		s="";
		for(int i=0;i<n;++i) s+="a";
		all=s;
		flag=0;
		if(n>4) sbsolve();
		else spsolve();
		cout<<"! "<<s<<endl;
		fflush(stdout);
		if(!read()) return 0;
	}
	return 0;
}
//ore no turn,draw!