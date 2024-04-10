#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
string a,b,ans;
int v1,v2;
int n;
int value3(int x)
{
	rep(i,n)
	{
		if(x<=i&&i<=x+2) cout<<'T';
		else cout<<'F';
	}
	cout<<endl;
	int value;
	cin>>value;
	value=(value-v1+3)>>1;
	return value;
}
int value2(int x)// return 0 for FT , 1 for TT/FF , 2 for TF
{
	rep(i,n)
	{
		if(x<=i&&i<=x+1) cout<<("TF"[i&1]);
		else cout<<("FT"[i&1]);
	}
	cout<<endl;
	int value;
	cin>>value;
	value-=v2;
	if(x&1) value=-value;
	return (2+value)>>1;
}
string begin3(int i)
{
	int q=value3(i);
	if(q==0)
	{
		return "FFF";
	}
	else if(q==3)
	{
		return "TTT";
	}
	else
	{
		int qq=value2(i);
	//	cout<<qq<<endl;
		if(q==1)
		{
			switch(qq)
			{
				case 0:
					return "FTF";
				case 1:
					return "FFT";
				case 2:
					return "TFF";
			}
		}
		else
		{
			switch(qq)
			{
				case 0:
					return "FTT";
				case 1:
					return "TTF";
				case 2:
					return "TFT";
			}
		}
	}
	return "???";
}
int main()
{
	ios_base::sync_with_stdio(false); 
	cin>>n;
	if(n==1)
	{
		cout<<"F"<<endl;
		int v;
		cin>>v;
		if(!v)
		cout<<"T"<<endl;
		return 0;
	}
	else if(n==2)
	{
		cout<<"FF"<<endl;
		int v;
		cin>>v;
		if(v!=2)
		{
			cout<<"FT"<<endl;
			cin>>v;
			if(v!=2)
			{
				cout<<"TF"<<endl;
				if(v!=2)
				{
					cout<<"TT"<<endl;
				}
			}
		}
		return 0;
	}
	rep(i,n)
	{
		a+='F';
		b+="FT"[i&1];
	}
	cout<<a<<endl;cin>>v1;
	cout<<b<<endl;cin>>v2;
	rep(i,n/3)
	{
		ans+=begin3(i*3);
	}
	if(n%3==2)
	{
		ans+=begin3(n-3).substr(1);
	}
	else if(n%3==1)
	{
		ans+=begin3(n-3)[2];
	}
	cout<<ans<<endl;
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not  or few affect?
*/

//luogu!