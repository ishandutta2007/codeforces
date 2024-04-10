#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[100005];
int o[100005],x[100005],y[100005];
Pi P[100005];
int cnt[200005],mex[100005];
int main(){
	const int sz=2000;
	int n,q;
	scanf("%d%d",&n,&q);
	Vi vv;
	fup(i,1,n,1){
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	vector<pair<int,Pi>> Q;
	fup(i,0,q-1,1){
		scanf("%d%d%d",o+i,x+i,y+i);
		if(o[i]==1){
			Q.pb({i,{x[i],y[i]}});
		}else{
			vv.pb(y[i]);
		}
	}
	COMPRESS(vv);
	fup(i,1,n,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	fup(i,0,q-1,1){
		if(o[i]==2){
			y[i]=lower_bound(ALL(vv),y[i])-vv.begin();
			P[i]={a[x[i]],y[i]};
			a[x[i]]=y[i];
		}
	}
	fdn(i,q-1,0,1){
		if(o[i]==2){
			a[x[i]]=P[i].X;
		}
	}
	sort(ALL(Q),[&](pair<int,Pi> p1,pair<int,Pi> p2){
		iii i1={p1.X/sz,p1.Y.X/sz,p1.Y.Y},i2={p2.X/sz,p2.Y.X/sz,p2.Y.Y};
		return i1<i2;
	});
	int t=0;
	int L=1,R=1;
	cnt[a[1]]++,mex[1]++;
	VPi ans;
	for(auto [i,pp]:Q){
		auto [l,r]=pp;
		while(t<i){
			if(o[t]==2){
				int pos=x[t];
				if(L<=pos && pos<=R){
					mex[cnt[a[pos]]]--;
					cnt[a[pos]]--;
					mex[cnt[a[pos]]]++;
				}
				a[pos]=P[t].Y;
				if(L<=pos && pos<=R){
					mex[cnt[a[pos]]]--;
					cnt[a[pos]]++;
					mex[cnt[a[pos]]]++;
				}
			}
			t++;
		}
		while(t>i){
			if(o[t]==2){
				int pos=x[t];
				if(L<=pos && pos<=R){
					mex[cnt[a[pos]]]--;
					cnt[a[pos]]--;
					mex[cnt[a[pos]]]++;
				}
				a[pos]=P[t].X;
				if(L<=pos && pos<=R){
					mex[cnt[a[pos]]]--;
					cnt[a[pos]]++;
					mex[cnt[a[pos]]]++;
				}
			}
			t--;
		}
		while(L>l){
			L--;
			mex[cnt[a[L]]]--;
			cnt[a[L]]++;
			mex[cnt[a[L]]]++;
		}
		while(R<r){
			R++;
			mex[cnt[a[R]]]--;
			cnt[a[R]]++;
			mex[cnt[a[R]]]++;
		}
		while(L<l){
			mex[cnt[a[L]]]--;
			cnt[a[L]]--;
			mex[cnt[a[L]]]++;
			L++;
		}
		while(R>r){
			mex[cnt[a[R]]]--;
			cnt[a[R]]--;
			mex[cnt[a[R]]]++;
			R--;
		}
		fup(j,1,5000,1){
			if(mex[j]==0){
				ans.pb(mp(i,j));
				break;
			}
		}
	}
	sort(ALL(ans));
	for(auto [x,y]:ans)printf("%d\n",y);
}