#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
char readop(){
	char ch=getchar();
	for(;ch!='-'&&ch!='+';ch=getchar());
	return ch;
}
const int N=505;
const int mod=998244353;

int n,f[N][N],ans;
struct node{
	char op;
	int x;
}a[N];
void upd(int &x,int y){x=(x+y)%mod;}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		char op=readop();
		a[i].op=op;
		if(op=='+') a[i].x=read();
	}
	for(int i=1;i<=n;i++) if(a[i].op=='+'){
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int j=0;j<i-1;j++){
			for(int k=0;k<=j;k++) if(f[j][k]){
				if(a[j+1].op=='-'){
					if(k) upd(f[j+1][k-1],f[j][k]);
					else upd(f[j+1][0],f[j][k]); 
				}
				else if(a[j+1].x<a[i].x) upd(f[j+1][k+1],f[j][k]);
				else upd(f[j+1][k],f[j][k]);
				upd(f[j+1][k],f[j][k]);
			}
		}
		for(int j=0;j<=n;j++) f[i][j]=f[i-1][j];
		for(int j=i;j<n;j++){
			for(int k=0;k<=j;k++) if(f[j][k]){
				if(a[j+1].op=='-'){
					if(k) upd(f[j+1][k-1],f[j][k]);
				}
				else if(a[j+1].x<=a[i].x) upd(f[j+1][k+1],f[j][k]);
				else upd(f[j+1][k],f[j][k]);
				upd(f[j+1][k],f[j][k]);
			}
		}
		for(int j=0;j<=n;j++) upd(ans,1LL*f[n][j]*a[i].x%mod);
	}
	cout<<ans<<'\n';
	return 0;
}