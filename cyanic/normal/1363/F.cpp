#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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
 
const int N=2005;
int f[N][N],g[N],c[26],nw[26],n;
char s[N],t[N];
 
int main(){
	int T; cin >> T;
	while(T--){
	cin >> n;
	scanf("%s%s",s+1,t+1);
	memset(c, 0, sizeof(c));
	memset(nw, 0, sizeof(nw));
	int flag=0;
	rep(i,1,n){
		int p=s[i]-'a';
		nw[p]++;
		g[i]=g[i-1];
		while(g[i]<n&&c[p]<nw[p]){
			g[i]++;
			c[t[g[i]]-'a']++;
		}
		if(c[p]<nw[p]){
			puts("-1");
			flag=1;
		}
		//cout<<i<<" "<<g[i]<<endl;
	}
	if(flag) continue;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) f[i][j] = -1e9;
	f[0][0]=0;
	rep(i,0,n) rep(j,0,n){
		if(i&&j&&s[i]==t[j]&&g[i]<=j) f[i][j]=f[i-1][j-1]+1;
		if(i) f[i][j]=max(f[i][j],f[i-1][j]);
		if(j) f[i][j]=max(f[i][j],f[i][j-1]);
		//cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	cout<<n-f[n][n]<<endl;
	}
	return 0;
}