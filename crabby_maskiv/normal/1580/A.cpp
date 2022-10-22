#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400+5;
const int inf=0x3f3f3f3f;
int n,m;
int w[N][N];
char a[N][N];
int main(){
	int i,j,k,l,r;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>(a[i]+1);
		for(i=1;i<=m;i++)
			for(j=1;j<=m;j++) w[i][j]=inf;
		int ans=inf;
		for(i=5;i<=n;i++){
			for(l=1;l<=m;l++){
				int cur=(a[i-1][l]!='1')+(a[i-2][l]!='1')+(a[i-3][l]!='1')
				+(a[i-1][l+1]!='0')+(a[i-2][l+1]!='0')+(a[i-3][l+1]!='0')+(a[i-4][l+1]!='1')
				+(a[i-1][l+2]!='0')+(a[i-2][l+2]!='0')+(a[i-3][l+2]!='0')+(a[i-4][l+2]!='1');
				int cnt=(a[i][l+1]!='1')+(a[i][l+2]!='1');
				for(r=l+3;r<=m;r++){
					w[l][r]=min(w[l][r],cur+(a[i-1][r]!='1')+(a[i-2][r]!='1')+(a[i-3][r]!='1'));
					ans=min(ans,cnt+w[l][r]);
					cnt+=(a[i][r]!='1');
					cur+=(a[i-1][r]!='0')+(a[i-2][r]!='0')+(a[i-3][r]!='0')+(a[i-4][r]!='1');
				}
			}
			for(l=1;l<=m;l++){
				int cnt=(a[i][l]!='1')+(a[i][l+1]!='0')+(a[i][l+2]!='0');
				for(r=l+3;r<=m;r++){
					w[l][r]+=cnt+(a[i][r]!='1');
					cnt+=(a[i][r]!='0');
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}