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
const int N=105;

int n,id[N][N],a[N][N];
void solve(){
	int _=0;
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) id[j][i]=++_;
	}
	if(n==2){
		cout<<"-1\n";
		return;
	}
	if(n==3){
		cout<<"2 9 7\n4 6 3\n1 8 5\n";
		return;
	}
	for(int i=1;i<=n;i++){
		int pv=1,cc=1;
		while(pv<=n){
			a[i][pv]=id[i][cc];
			cc++;
			pv+=2;
		}
		pv=2;
		while(pv<=n){
			a[i][pv]=id[i][cc];
			cc++;
			pv+=2;
		}
	}
	int pv=1;
	while(pv<=n){
		for(int i=1;i<=n;i++) cout<<a[pv][i]<<' ';
		cout<<'\n';
		pv+=2;
	}
	pv=2;
	while(pv<=n){
		for(int i=n;i;i--) cout<<a[pv][i]<<' ';
		cout<<'\n';
		pv+=2;
	}
}

int main(){
	int T=read();
	while(T--) solve();
	return 0;
}