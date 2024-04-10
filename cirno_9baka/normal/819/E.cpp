#include<bits/stdc++.h>
using namespace std;
const long long M=(1ll<<32);
const int N=500005;
struct str{
	int a,b,c,d;
};
struct node{
	int a,b,c;
};
vector<str> ans;
vector<node> ans2;
void Out43(int a[])
{
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[5],a[2],a[7]});
	ans.push_back((str){a[1],a[6],a[2],a[7]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[5],a[4],a[7]});
	ans.push_back((str){a[3],a[6],a[4],a[7]});
}
void Out44(int a[])
{
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[7],a[2],a[8]});
	ans.push_back((str){a[1],a[7],a[2],a[8]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[7],a[4],a[8]});
	ans.push_back((str){a[3],a[7],a[4],a[8]});
}
void Out45(int a[])
{
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[7],a[2],a[8]});
	ans.push_back((str){a[1],a[7],a[2],a[9]});
	ans.push_back((str){a[1],a[8],a[2],a[9]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[7],a[4],a[8]});
	ans.push_back((str){a[3],a[7],a[4],a[9]});
	ans.push_back((str){a[3],a[8],a[4],a[9]});
}
void Out46(int a[])
{
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[5],a[2],a[6]});
	ans.push_back((str){a[1],a[7],a[2],a[8]});
	ans.push_back((str){a[1],a[7],a[2],a[8]});
	ans.push_back((str){a[1],a[9],a[2],a[10]});
	ans.push_back((str){a[1],a[9],a[2],a[10]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[5],a[4],a[6]});
	ans.push_back((str){a[3],a[7],a[4],a[8]});
	ans.push_back((str){a[3],a[7],a[4],a[8]});
	ans.push_back((str){a[3],a[9],a[4],a[10]});
	ans.push_back((str){a[3],a[9],a[4],a[10]});
}
void Out3(int a[])
{
	ans2.push_back((node){a[1],a[2],a[3]});
	ans2.push_back((node){a[1],a[2],a[3]});
}
void Out4(int a[])
{
	ans2.push_back((node){a[1],a[2],a[3]});
	ans2.push_back((node){a[1],a[2],a[4]});
	ans2.push_back((node){a[1],a[3],a[4]});
	ans2.push_back((node){a[2],a[3],a[4]});
}
void Out5(int a[])
{
	ans.push_back((str){a[2],a[3],a[4],a[5]});
	ans.push_back((str){a[2],a[3],a[4],a[5]});
	ans2.push_back((node){a[1],a[2],a[4]});
	ans2.push_back((node){a[1],a[2],a[4]});
	ans2.push_back((node){a[1],a[3],a[5]});
	ans2.push_back((node){a[1],a[3],a[5]});
}
void Out6(int a[])
{
	ans2.push_back((node){a[1],a[2],a[3]});
	ans2.push_back((node){a[1],a[2],a[4]});
	ans2.push_back((node){a[1],a[3],a[5]});
	ans2.push_back((node){a[1],a[4],a[6]});
	ans2.push_back((node){a[1],a[5],a[6]});
	ans2.push_back((node){a[2],a[3],a[6]});
	ans2.push_back((node){a[2],a[4],a[5]});
	ans2.push_back((node){a[2],a[5],a[6]});
	ans2.push_back((node){a[3],a[4],a[5]});
	ans2.push_back((node){a[3],a[4],a[6]});
}
int n,i,p[100005],k,a[15],j,m;
int main()
{
	scanf("%d",&n);
	m=n;
	while(n>6)
	{
		++k;
		n-=4;
	}
	if(n==3)
	{
		a[1]=m-2,a[2]=m-1,a[3]=m;
		Out3(a);
		a[5]=m-2,a[6]=m-1,a[7]=m;
		for(i=1;i<=k;++i)
		{
			a[1]=i*4-3;
			a[2]=i*4-2;
			a[3]=i*4-1;
			a[4]=i*4;
			Out43(a);
		}
	}
	if(n==4)
	{
		a[1]=m-3,a[2]=m-2,a[3]=m-1,a[4]=m;
		Out4(a);
		a[5]=m-3,a[6]=m-2,a[7]=m-1,a[8]=m;
		for(i=1;i<=k;++i)
		{
			a[1]=i*4-3;
			a[2]=i*4-2;
			a[3]=i*4-1;
			a[4]=i*4;
			Out44(a);
		}
	}
	if(n==5)
	{
		a[1]=m-4,a[2]=m-3,a[3]=m-2,a[4]=m-1,a[5]=m;
		Out5(a);
		a[5]=m-4,a[6]=m-3,a[7]=m-2,a[8]=m-1,a[9]=m;
		for(i=1;i<=k;++i)
		{
			a[1]=i*4-3;
			a[2]=i*4-2;
			a[3]=i*4-1;
			a[4]=i*4;
			Out45(a);
		}
	}
	if(n==6)
	{
		a[1]=m-5,a[2]=m-4,a[3]=m-3,a[4]=m-2,a[5]=m-1,a[6]=m;
		Out6(a);
		a[5]=m-5,a[6]=m-4,a[7]=m-3,a[8]=m-2,a[9]=m-1,a[10]=m;
		for(i=1;i<=k;++i)
		{
			a[1]=i*4-3;
			a[2]=i*4-2;
			a[3]=i*4-1;
			a[4]=i*4;
			Out46(a);
		}
	}
	for(i=1;i<=k;++i)
	{
		a[1]=i*4-3;
		a[2]=i*4-2;
		a[3]=i*4-1;
		a[4]=i*4;
		Out4(a);
	}
	for(i=1;i<=k;++i)
		for(j=i+1;j<=k;++j)
		{
			a[1]=i*4-3;
			a[2]=i*4-2;
			a[3]=i*4-1;
			a[4]=i*4;
			a[5]=j*4-3;
			a[6]=j*4-2;
			a[7]=j*4-1;
			a[8]=j*4;
			Out44(a);
		}
	cout<<ans.size()+ans2.size()<<endl;
	for(auto it:ans)
		printf("4 %d %d %d %d\n",it.a,it.b,it.c,it.d);
	for(auto it:ans2)
		printf("3 %d %d %d\n",it.a,it.b,it.c);
	
}