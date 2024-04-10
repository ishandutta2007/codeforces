#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int n;
int res;
int lst,nw;
int main()
{
	scanf("%d%d",&n,&lst);
	res=lst;
	if(n==1)
	{
		cout<<lst<<endl;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d",&nw);
		res=min(res,max(lst,nw));
		lst=nw;
	}
	res=min(res,nw);
	printf("%d\n",res);
	return 0;
}
/*
4
10 3 5 10

5
10 2 8 3 5

5
1 1 1 1 1

5
2 1 2 1 2

5
1 5 5 5 5

5
5 5 5 5 1

*/