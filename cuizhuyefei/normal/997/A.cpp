#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 555555;
int n,x,y;char s[N];ll res,cnt;
int main() {
	read(n);read(x);read(y);scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='0'){
		int j;for(j=i;j<=n;j++)if(s[j]=='1')break;
	//	cerr<<i<<' '<<j<<endl;
		cnt++;i=j-1;
	}
	while (x<y&&cnt>1){cnt--;res+=x;}
	res+=y*cnt;
	cout<<res;
	return 0;
}