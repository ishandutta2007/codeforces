#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 200010
#define MAXL 17
#define INF 1e9

int A,B,C,D;

int pre(int st, int en){
	int V[] = {A,B,C,D};
	--V[st];
	--V[en];
	if(V[1]-V[0] == V[2]-V[3])return 1;
	return 0;
}

void T(int st, int en){
	int V[] = {A,B,C,D};
	--V[st];
	--V[en];

	for (int l=1;l<=6;++l){
		for (int bm=0;bm<(1<<l);++bm){
			int zeroone = V[0];
			int twothree = V[3];
			int onetwo = V[1] - V[0];
			int zero=-1;
			int one = -1;
			int two=-1;
			vi out;
			out.pb(st);
			int cur = st;
			int fail = 0;

			for (int i=0;i<l;++i){
				if (bm & (1<<i))++cur;
				else --cur;
				if (cur < 0 || cur > 3){fail=1;break;}
				out.pb(cur);
			}
			if(fail)continue;

			if(out.back()!=en)continue;

			for (int i=0;i<l;++i){
				int t = out[i]; int q = out[i+1];
				assert(abs(t-q)==1);
				if (min(t,q) == 2){
					--twothree;
					two=i;
				}
				if (min(t,q) == 1){--onetwo;one=i;}
				if (min(t,q) == 0){--zeroone;zero=i;}
				if (min({twothree,onetwo,zeroone}) < 0)break;
			}
			if (min({twothree,onetwo,zeroone}) < 0)continue;
			// cout<<zeroone<<' '<<onetwo<<' '<<twothree<<'\n';

			if (zero==-1&& zeroone)continue;
			if (one==-1 && onetwo)continue;
			if (two==-1&& twothree)continue;
			if (zeroone%2==1||onetwo%2==1||twothree%2==1)continue;
			cout<<"YES\n";
			for (int i=0;i<l;++i){
				cout<<out[i]<<' ';
				if (i == zero)while (zeroone){cout<<out[i+1]<<' '<<out[i]<<' ';zeroone-=2;}
				if (i == one)while (onetwo){cout<<out[i+1]<<' '<<out[i]<<' ';onetwo-=2;}
				if (i == two)while (twothree){cout<<out[i+1]<<' '<<out[i]<<' ';twothree-=2;}
			}
			cout<<out.back();
			exit(0);
		}
	}
}

int main(){
	cin>>A>>B>>C>>D;
	if (D > C){
		if (A == 0 && B == 0 && C == D-1){
			cout<<"YES\n";
			for (int i=0;i<C;++i)cout<<"3 2 ";
			cout<<"3";
			return 0;
		}else{
			cout<<"NO\n";
			return 0;
		}
	}
	if (A > B){
		if (C == 0 && D == 0 && B == A-1){
			cout<<"YES\n";
			for (int i=0;i<B;++i)cout<<"0 1 ";
			cout<<"0";
			return 0;
		}else{
			cout<<"NO\n";
			return 0;
		}
	}
	if (B == 1 && A+B+C+D == 1){cout<<"YES\n1";return 0;}
	if (C == 1 && A+B+C+D == 1){cout<<"YES\n2";return 0;}
	A*=2;B*=2;C*=2;D*=2;
	bool works = 0;
	bool flag=0;
	for (int st=0;st<=3;++st){
		for (int en = 0; en <= 3;++en){
			if (pre(st,en)){T(st,en);flag=1;}
		}
	}
	cout<<"NO\n";
}