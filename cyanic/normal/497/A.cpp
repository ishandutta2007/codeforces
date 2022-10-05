#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=105;
vector<pii> f[N];
char s[N][N];
int n,m,ans;

int main(){
	read(n),read(m);
	rep(i,1,n){
		scanf("%s",s[i]+1);
	}
	f[1].pb(mp(1,n));
	rep(i,1,m){
		int flag=0;
		for(auto x:f[i]){
			int l=x.fi,r=x.se;
			rep(k,l,r){
				if(k>l&&s[k][i]<s[k-1][i]){
					flag=1; break;
				}
				int las=k;
				while(k<r&&s[k][i]==s[k+1][i]) k++;
				f[i+1].pb(mp(las,k));
			}
			if(flag) break;
		}
		if(flag){
			ans++;
			f[i+1]=f[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}