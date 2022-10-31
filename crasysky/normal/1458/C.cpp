#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1003; int n,a[3][N][N],rev[3],r[3],d[3],ad[3],ans[N][N];
char s[100005];
void down(int i,int t){ d[i]+=t; }
void right(int i,int t){ r[i]+=t; }
void add(int i,int t){ ad[i]+=t; }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int q; scanf("%d%d",&n,&q);
		rep(i,0,n-1) rep(j,0,n-1){
			int x; scanf("%d",&x); --x;
			a[0][i][j]=x,a[1][i][x]=j,a[2][x][j]=i;
		}
		scanf("%s",s);
		int arr=0,row=1,col=2; 
		rev[0]=rev[1]=rev[2]=r[0]=r[1]=r[2]=d[0]=d[1]=d[2]=ad[0]=ad[1]=ad[2]=0;
		rep(i,1,q){
			char c=s[i-1];
			if (c=='I') swap(arr,row),rev[col]^=1,swap(r[col],d[col]);
			if (c=='C') swap(arr,col),rev[row]^=1,swap(r[row],d[row]);
			if (c=='R') right(arr,1),add(row,1),right(col,1);
			if (c=='L') right(arr,-1),add(row,-1),right(col,-1);
			if (c=='D') down(arr,1),down(row,1),add(col,1);
			if (c=='U') down(arr,-1),down(row,-1),add(col,-1);
		}
		rep(i,0,n-1) rep(j,0,n-1) ans[i][j]=rev[arr]?a[arr][j][i]:a[arr][i][j];
		int rr=(r[arr]%n+n)%n,dd=(d[arr]%n+n)%n,aa=(ad[arr]%n+n)%n;
		rep(i,0,n-1){
			rep(j,0,n-1)
				printf("%d ",(ans[(i-dd+n)%n][(j-rr+n)%n]+aa)%n+1);
			putchar('\n');
		}
		if (T) putchar('\n');
	}
	return 0;
}