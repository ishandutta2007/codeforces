#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

//100  {0}  wu  //,}  //  //uoj
int op[10]=
{
	9,99,999,9999,99999,999999,9999999,99999999,999999999
};
//fenhe
int g, l,ll,   ans,k,u,n;


//\n //_ //
inline void check(int n, int k)
{
	if(n+1>=k)
	{
		ans+=(k-1)/2;
		return ;
	}
	ans+=n-k/2;//return //;
}

int main()
{
	n=read();
	if(n==2)
	{
		puts("1");
		return 0;//exit (0)
	}
	if(n==3)
	{
		puts("3");
		return 0;//exit (0)
	}
	if(n==4)
	{
		puts("6");
		return 0;//exit (0)
	}
	
	for(g=8; g>=0; --g)
	{ //  _ // \n ///
		if(n+n-1>=op[g])break;
	}
	k=op[g];
	u=op[g]+1;
	
	while(1)
	{
		//_
		check(n,k);
		if(k>=1000000000)break; //ll/    1e9 double //10000000000  //ll ull l //  100 1000  ^2 //zxts  dlqz
		k+=u;
		if(n+n-1<k)break;
	}
	printf("%d\n",ans);//ans ab //_ //return 0;    cin cout  scanf   &    s no   shuzu  // cerr  throw  //re
}//;a