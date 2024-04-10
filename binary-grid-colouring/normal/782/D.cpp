#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize ("O3")
typedef long long ll;
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
map<string,int>s1;
map<string,int>s2;
string name[1234][3];
int main()
{
	int n;
	string s,t;
	int flag1 = 1,flag2 = 1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>t;
		for(int j=0;j<2;j++)
		{
			name[i][0] += s[j];
			name[i][1] += s[j];
		}
		name[i][0] += s[2];
		name[i][1] += t[0];
		
		if(s1[name[i][0]]==0)
		{
			s1[name[i][0]] = 1;
		}
		else flag1 = 0;
		
		if(s2[name[i][1]]==0)
		{
			s2[name[i][1]] = 1;
		}
		else flag2 = 0;
	} 
	if(flag1 == 1)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<name[i][0]<<endl;
		}
	}
	else if(flag2 == 1)
	{
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<name[i][1]<<endl;
		}	    
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}