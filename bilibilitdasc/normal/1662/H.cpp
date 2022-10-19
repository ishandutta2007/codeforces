// 
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define re return
#define all(a) a.begin(),a.end()
#define int long long
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int MOD=1000000007,INF=1000000000000000000;
template<typename T>inline void Mx(T &a,T b){a=max(a,b);}
template<typename T>inline void Mi(T &a,T b){a=min(a,b);}
inline int ad(int &a,int b,int c=MOD){re a=(a+b)%c;}
template<typename T>inline T read(){T a;cin>>a;re a;}
inline bool is_digit(int msk,int d){re (msk>>d)&1;}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool chk(int n,int m,int a){
	if(a==1)re 1;
	if(n%a>1)re 0;
	int rst=n%a+m-1;
	if(rst%a>1)re 0;
	rst=rst%a+n-1;
	if(rst%a>1)re 0;
	rst=rst%a+m-1;
	if(rst%a!=1)re 0;
	re 1;
}
void run(){
	int n,m;
	cin>>n>>m;
	int tot=n+n+m+m-4;
	vi v;
	for(int i=1;i*i<=tot;i++){
		if(tot%i==0&&(chk(n,m,i)||chk(m,n,i)))v.pb(i);
		if(tot%i==0&&i*i!=tot&&(chk(n,m,tot/i)||chk(m,n,tot/i)))v.pb(tot/i);
	}
	sort(all(v));
	cout<<sz(v)<<" ";
	rep(i,sz(v))cout<<v[i]<<" ";
	cout<<"\n"; 
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	for(int tc=read<int>();tc;tc--)
		run();
	re 0;
}