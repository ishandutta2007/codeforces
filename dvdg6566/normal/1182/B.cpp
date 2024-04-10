#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 510

int vert[MAXN], hori[MAXN];
int H,W;
int A[MAXN][MAXN];
string S;
vi VL,VU;
vi HL,HU;

void over(){
	cout<<"NO";
	exit(0);
}
int dx[] = {1,-1,0,0,0};
int dy[] = {0,0,1,-1,0};

int T = 0;

void dfs(int x, int y,int k){
	--T;
	int tx = x +dx[k];
	int ty = y + dy[k];
	if (tx<0||ty<0)return;
	if (A[tx][ty] == 0)return;
	dfs(tx,ty,k);
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>H>>W;
	for (int i=0;i<H;++i){
		cin>>S;
		for (int j=0;j<W;++j){
			A[i][j] = (S[j] == '*');
		}
	}
	for (int i=0;i<H;++i){
		for (int j=0;j<W;++j){
			if (A[i][j]){++hori[i];++vert[j];++T;}
		}
	}
	for (int i=0;i<H;++i){
		if (hori[i])HL.pb(i);
	}
	if (!SZ(HL))over();
	int l = HL.back() - HL[0] + 1;
	if (SZ(HL) != l)over();
	for (auto i : HL){
		if (hori[i] > 1)HU.pb(i);
	}
	if (SZ(HU)!=1)over();

	for (int i=0;i<W;++i){
		if (vert[i])VL.pb(i);
	}
	if (!SZ(VL))over();
	l = VL.back() - VL[0] + 1;
	if (SZ(VL) != l)over();
	for (auto i : VL){
		if (vert[i] > 1)VU.pb(i);
	}
	if (SZ(VU)!=1)over();
	if (HU[0] == 0 || VU[0] == 0)over();
	for (int k=0;k<5;++k){
		if (A[HU[0] + dx[k]][VU[0] + dy[k]] == 0)over();
	}
	--T;
	for (int k=0;k<4;++k){
		dfs(HU[0] + dx[k], VU[0] + dy[k], k);
	}
	if (T!=0)over();
	cout<<"YES";
}