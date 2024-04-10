#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 1e6 + 5, pod = (1 << 19), inf = 1e9 + 5, mod = 1e9 + 7, mod2 = mod - 1;

struct matrix{
	ll a[5][5];
	matrix ()
	{
		memset(a,0,sizeof(a));
	}
	matrix operator * ( const matrix x )
	{
		matrix d=matrix();
		for(int i=0;5>i;i++)
			for(int k=0;5>k;k++)
				for(int j=0;5>j;j++)
					d.a[i][j]=(d.a[i][j]+(ll)a[i][k]*x.a[k][j] % mod2)%mod2;
		return d;
	}
};
matrix pot(matrix x , ll k)
	{
		k--;
		matrix ans = x;
		while(k>0)
		{
			if(k%2==1)
				ans=ans*x;
			x=x*x;
			k/=2;
		}
		return ans;
	}
void cat ( matrix A )
{
	for(int i=0;5>i;i++)
		{
			for(int j=0;5>j;j++)
				cout<<A.a[i][j]<<" ";
			cout<<endl;
		}
}

ll n, a, b, c, e;

int pt(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

int pt2(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1)
			res = res * a % mod2;
		a = a * a % mod2;
		b /= 2;
	}
	return res;
}

int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	cin >> n >> a >> b >> c >> e;
	matrix M = matrix();
	M.a[1][0] = 1;
	M.a[2][1] = 1;
	M.a[1][2] = M.a[0][2] = M.a[2][2] = 1;
	M = pot(M, n - 1);
	ll ans = 0;
	
	matrix lose = matrix();
	lose.a[1][0] = lose.a[2][1] = lose.a[0][2] = lose.a[1][2] = lose.a[2][2] = lose.a[3][2] = lose.a[3][3] = lose.a[4][3] = lose.a[4][4] = 1;
	matrix Begin = matrix();
	Begin.a[0][3] = Begin.a[0][4] = 2;
	lose = pot(lose, n - 3);
	Begin = Begin * lose;
	
	ans = pt(e, Begin.a[0][2]);
	
	
	
	
	matrix AA = matrix(), BB = matrix(), CC = matrix();
	AA.a[0][0] = 1;
	BB.a[0][1] = 1;
	CC.a[0][2] = 1;
	AA = AA * M;
	BB = BB * M;
	CC = CC * M;
	ans = ans * pt(a, AA.a[0][0]) % mod;
	ans = ans * pt(b, BB.a[0][0]) % mod;
	ans = ans * pt(c, CC.a[0][0]) % mod;
	cout << ans;	
	
		
	
		
	
    return 0;
}