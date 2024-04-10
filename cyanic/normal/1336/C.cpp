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

const int N=3005,mod=998244353;
int f[N][N<<1],n,m,ans;
char s[N],t[N];

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	rep(i,1,n+1) f[i][i-1]=1;
	rep(len,1,n) rep(l,1,n+2-len){
		int r=l+len-2;
		if(!f[l][r]) continue;
		//printf("# %d %d  %d\n",l,r,f[l][r]);
		if(l>m+1||l>=2&&s[len]==t[l-1]) add(f[l-1][r],f[l][r]);
		if(r>=m||s[len]==t[r+1]) add(f[l][r+1],f[l][r]);
	}
	rep(i,m,n) add(ans,f[1][i]);
	cout<<ans<<endl;
	return 0;
}