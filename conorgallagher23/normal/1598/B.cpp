#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define mp make_pair
#define fi first
#define se second
using namespace std;
template<typename T>void read(T &x){
	char c=getchar();int f=1;x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	x*=f;
}
int n,a[N][5];
void solve(){
	read(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=5;j++)read(a[i][j]);
	for(int i=1;i<=5;i++)for(int j=i+1;j<=5;j++){
		bool fl=1;
		for(int k=1;k<=n;k++)if(!a[k][i]&&!a[k][j]){
			fl=0;
			break;
		}
		if(!fl)continue;
		int A=0,B=0;
		for(int k=1;k<=n;k++){
			if(a[k][i])A++;
			if(a[k][j])B++;
		}
		if(A>=n/2&&B>=n/2){
			cout<<"YES\n";
			return;
		} 
	}
	cout<<"NO\n";
}
int main(){
	int T;read(T);
	while(T--)solve();
	return 0;
}