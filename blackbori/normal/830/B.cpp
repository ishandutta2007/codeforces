#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll T[101010],A[101010],B[101010];
ll n,ans,k;

ll Put(ll idx,ll val)
{
	for(;idx<=n;idx+=(idx&-idx)){
		T[idx] += val;
	}

	return 0;
}

ll Get(ll idx)
{
	if(idx == 0) return 0;

	ll ret = 0;

	for(;idx;idx-=(idx&-idx)){
		ret += T[idx];
	}

	return ret;
}

ll Sum(ll l,ll r)
{
	if(l <= r) return Get(r) - Get(l);
	else return Sum(l,n) + Sum(0,r);
}

bool comp(ll a,ll b)
{
	return A[a] < A[b];
}

ll dist(ll l,ll r)
{
	if(l <= r) return r-l;
	else return dist(l,n) + dist(0,r);
}

bool comp2(int a,int b)
{
	return dist(k,a) < dist(k,b);
}

int main()
{
	ll i,a=0,b=0,l=0,r=0;

	scanf("%lld",&n);

	for(i=1;i<=n;i++){
		scanf("%lld",A+i);
		B[i] = i;
	}

	sort(B+1,B+n+1,comp);

	for(i=1;i<=n+1;i++){
		if(A[B[i]] != A[B[i-1]]){
			sort(B+l,B+r+1,comp2);
			l = r = i; 
			k = B[i-1];
		}
		else r = i;
	}

	for(i=1;i<=n;i++){
		Put(i,1);
	}

	for(i=1;i<=n;i++){
		a = b, b = B[i];
		ans += Sum(a,b);
//		printf("%lld %lld %lld\n",a,b,Sum(a,b));
		Put(b,-1);
	}

	printf("%lld\n",ans);

	return 0;
}