#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005,M=27;
int f[N][M][M],a[N],n,m,top;
char s[N],stk[N];

int dfs(int k,int x,int y,int flag){
	if(!k)return !flag;
	int lea=(flag?a[n-k+1]:1);
	//cerr<<k<<" "<<x<<" "<<y<<" "<<flag<<endl;
	rep(i,lea,m)
		if((!y||f[k-1][y][i])&&i!=x&&i!=y)
			if(dfs(k-1,y,i,flag&&i==lea)){
				stk[++top]='a'+i-1;
				return 1;
			}
	return 0;
}

int main(){
	read(n),read(m);
	scanf("%s",s+1);
	rep(i,1,n)a[i]=s[i]-'a'+1;
	rep(x,1,M)rep(y,1,M)
		f[0][x][y]=1;
	rep(i,1,n)rep(x,1,M)rep(y,1,M){
		rep(z,1,M)
			if(z!=x&&z!=y&&f[i-1][y][z]){
				f[i][x][y]=1;
				break;
			}
	}
	if(!dfs(n,0,0,1))puts("NO");
	else{
		while(top)putchar(stk[top--]);
		puts("");
	}
	return 0;
}