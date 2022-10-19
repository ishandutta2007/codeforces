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
//ios_base::sync_with_stdio(false);???cin
unsigned time_related_rand()
{
	return ll(chrono::high_resolution_clock::now().time_since_epoch().count());
}
int n;
vector<int> N;
vector<int> A[4];
bool Askfor(const vector<int>&a,const vector<int>&b)
{
	cout<<"? "<<a.size()+b.size();
	rep(i,a.size()) cout<<" "<<a[i];
	rep(i,b.size()) cout<<" "<<b[i];
	cout<<endl;
	string s;
	cin>>s;
	if(s=="YES") return true;
	else return false;
}
bool Askfor(int v)
{
	cout<<"? 1 "<<v<<endl;
	string s;
	cin>>s;
	if(s=="YES") return true;
	else return false;
}
void remove(const vector<int>&a,const vector<int>&b,const vector<int>&c)
{
	N.clear();
	rep(i,a.size()) N.pb(a[i]);
	rep(i,b.size()) N.pb(b[i]);
	rep(i,c.size()) N.pb(c[i]);
}
void Query(int x,int y)
{
	cout<<"! "<<x<<endl;
	string s;cin>>s;
	if(s==":)") exit(0);
	cout<<"! "<<y<<endl;
	exit(0);
}
void deduce()
{
	rep(i,4) A[i].clear();
	rep(i,N.size())
	{
		A[i&3].pb(N[i]); 
	}
	int a=Askfor(A[0],A[1]);
	int b=Askfor(A[0],A[2]);
	if(a==0&&b==0) remove(A[1],A[2],A[3]);
	else if(a==0) remove(A[0],A[2],A[3]);
	else if(b==0) remove(A[0],A[1],A[3]);
	else remove(A[0],A[1],A[2]);
}
const int v[16]={1,1,2,0,2,1,0,0,1,1,1,0,0,0,0,0};
void Query3()
{
	int x=Askfor(N[2]);
	int y=Askfor(N[1]);
	int z=Askfor(N[1]);
	int w=Askfor(N[2]);
	int u=v[x*8+y*4+z*2+w];
	if(u==2) Query(N[0],N[1]);
	else if(u==1) Query(N[0],N[2]);
	else Query(N[1],N[2]);
}
void Query2()
{
	Query(N[0],N[1]);
}
void Query1()
{
	Query(N[0],N[0]);
}
int main()
{
	cin>>n;
	rep1(i,n) N.pb(i);
	while(N.size()>=4) deduce();
	if(N.size()==3) Query3();
	else if(N.size()==2) Query2();
	else Query1();
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