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
int t;
int tp[100005];
ll l[100005],r[100005];
ll all[200005];
int tr[4][4]={
	0,1,2,3,  // 0: 01 1: 11 2: 00 3: 10
	1,1,2,2,
	2,1,2,1,
	3,1,2,0
};
struct Node{
	int value0,value1;
	Node(int A=0x3f3f3f3f,int B=0x3f3f3f3f)
	{
		value0=A;value1=B;
	}
};
Node operator+(const Node&a,const Node&b)
{
	return Node((a.value0!=0x3f3f3f3f)?(a.value0):(b.value0),(a.value1!=0x3f3f3f3f)?(a.value1):(b.value1));
}
Node operator+(const Node&a,int v)
{
	switch(v)
	{
		case 0:
			return a;
		case 1:
			return Node(0x3f3f3f3f,min(a.value0,a.value1));
		case 2:
			return Node(min(a.value0,a.value1),0x3f3f3f3f);
		case 3:
			return Node(a.value1,a.value0);
	}
	return Node();
}
Node operator+=(Node&a,const Node&b)
{
	return a=a+b;
}
Node operator+=(Node&a,int v)
{
	return a=a+v;
}
struct segtree{
	Node value[200005<<2];
	int opr[200005<<2];
	void pushdown(int i)
	{
		if(opr[i])
		{
			value[i<<1]+=opr[i];value[i<<1|1]+=opr[i];
			opr[i<<1]=tr[opr[i<<1]][opr[i]];opr[i<<1|1]=tr[opr[i<<1|1]][opr[i]];
			opr[i]=0;
		}
	}
	void maintain(int i)
	{
		value[i]=value[i<<1]+value[i<<1|1];
	}
	void build(int i,int l,int r)
	{
		value[i].value0=l;value[i].value1=0x3f3f3f3f;
		if(l<r)
		{
			int m=(l+r)>>1;
			build(i<<1,l,m);
			build(i<<1|1,m+1,r);
		}
	}
	void update(int i,int il,int ir,int ql,int qr,int tp)
	{
		if(il>qr||ql>ir) return;
		if(ql<=il&&ir<=qr)
		{
			value[i]+=tp;
			opr[i]=tr[opr[i]][tp];
			return;
		}
		pushdown(i);
		int m=(il+ir)>>1;
		update(i<<1,il,m,ql,qr,tp);
		update(i<<1|1,m+1,ir,ql,qr,tp);
		maintain(i);
	}
	Node query(int i,int il,int ir,int ql,int qr)
	{
		if(il>qr||ql>ir) return Node();
		if(ql<=il&&ir<=qr) return value[i];
		pushdown(i);
		int m=(il+ir)>>1;
		return query(i<<1,il,m,ql,qr)+query(i<<1|1,m+1,ir,ql,qr);
	}
	void PrintSegtreeStruture(int i,int il,int ir)
	{
		cout<<"We are now at the node "<<i<<" which is for ["<<il<<","<<ir<<"]"<<endl;
		cout<<"The MEX is "<<value[i].value0<<" , the MIN is "<<value[i].value1<<" , to operate the operation "<<opr[i]<<endl;
		if(il<ir)
		{
			cout<<"It has two sons to be traversed."<<endl;
			int m=(il+ir)>>1;
			PrintSegtreeStruture(i<<1,il,m);
			PrintSegtreeStruture(i<<1|1,m+1,ir);
		}
	}
};
segtree seg;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	rep(i,t)
	{
		cin>>tp[i]>>l[i]>>r[i];
		all[i<<1]=l[i];
		all[i<<1|1]=++r[i];
	}
	all[2*t]=1;
	sort(all,all+2*t+1);
	int v=unique(all,all+2*t+1)-all;
	rep(i,t)
	{
		l[i]=lower_bound(all,all+v,l[i])-all;
		r[i]=lower_bound(all,all+v,r[i])-all-1;
	}
	seg.build(1,0,v);
	rep(i,t)
	{
	//	cout<<l[i]<<' '<<r[i]<<' '<<tp[i]<<"!"<<endl;
		seg.update(1,0,v,l[i],r[i],tp[i]);
	//	seg.PrintSegtreeStruture(1,0,v);
	//	cout<<endl;
	//	cout<<seg.query(1,0,v,0,v).value0<<endl;
		cout<<all[seg.query(1,0,v,0,v).value0]<<endl;
	}
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