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
void run(){
	string s,t;
	cin>>s>>t;
	string a="",b="";
	int x=0,y=0;
	rep(i,sz(s)){
		if(s[i]!='B')a+=s[i];
		else x++;
	}
	rep(i,sz(t)){
		if(t[i]!='B')b+=t[i];
		else y++;
	}
	x%=2,y%=2;
	int i=0,j=0;
	while(i<sz(a)-1){
		if(i<0||a[i]!=a[i+1])i++;
		else a.erase(a.begin()+i),a.erase(a.begin()+i),i--;
	}
	while(j<sz(b)-1){
		if(j<0||b[j]!=b[j+1])j++;
		else b.erase(b.begin()+j),b.erase(b.begin()+j),j--;
	}
	if(a==b&&x==y){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	for(int tc=read<int>();tc;tc--)
		run();
	re 0;
}