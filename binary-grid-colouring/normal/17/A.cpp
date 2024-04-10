#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <unistd.h> 
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
bool isprime(int n)
{
	if(n<2)return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)return false;
	}
	return true;
}
set<int>se; 
int main()
{
	int n,k;
	cin>>n>>k;
	int last = -1;
	for(int i=2;i<=n;i++)
	{
		if(isprime(i))
		{
			if(last>=0)
			{
				if(last+i+1<=n && isprime(last+i+1))
				{
					se.insert(last+i+1);
				}
			}
			last = i;
		}
	 }
	 if(se.size()>=k)cout<<"YES"<<endl;
	 else cout<<"NO"<<endl;
	return 0;
}