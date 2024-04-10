#include <bits/stdc++.h>
/*????????code*/
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
//ios_base::sync_with_stdio(false);???cin
int Next[2888888][2];
int Cnt[2888888];
int cnt;
int q,tp,p,l;
void add(int v)
{
	int cur=1;++Cnt[cur];//cout<<"++"<<cur<<endl;
	per(i,27)
	{
		if(!Next[cur][(v>>i)&1])Next[cur][(v>>i)&1]=++cnt;
		cur=Next[cur][(v>>i)&1];++Cnt[cur];//cout<<"++"<<cur<<endl;
	}
}
void rem(int v)
{
	int cur=1;--Cnt[cur];//cout<<"--"<<cur<<endl;
	per(i,27)
	{
		cur=Next[cur][(v>>i)&1];--Cnt[cur];//cout<<"--"<<cur<<endl;
	}
}
int answer(int toxor,int toless)
{
	int cur=1,ans=0;
	per(i,27)
	{
	//	cout<<";;;"<<cur<<endl;
		if((toless>>i)&1)
		{
			ans+=Cnt[Next[cur][(toxor>>i)&1]];
		//	cout<<";;;;;"<<Cnt[Next[cur][(toxor>>i)&1]]<<endl;
			cur=Next[cur][1^((toxor>>i)&1)];
		}
		else
		{
			cur=Next[cur][(toxor>>i)&1];
		}
	}
	return ans;
}
void init()
{
	ios_base::sync_with_stdio(false);
	cnt=1;
	cin>>q;
}
void Query()
{
	cin>>tp;
	switch(tp)
	{
		case 1:
			cin>>p;add(p);break;
		case 2:
			cin>>p;rem(p);break;
		case 3:
			cin>>p>>l;cout<<answer(p,l)<<endl;break;
		default:
			exit(-1);
	}
}
int main()
{
	init();
	while(q--)
	Query();
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
2. If contains "not", why not ?????? or few affect?
*/