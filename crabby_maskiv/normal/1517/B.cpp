#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
int n,m;
int b[N][N];
int pos[N],l[N],r[N];
int ans[N][N];
int main(){
	int i,j;
	int _;cin>>_;
	for(i=0;i<N;i++) b[0][i]=1e9;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) cin>>b[i][j];
			sort(b[i]+1,b[i]+m+1);
		}
		for(i=1;i<=n;i++) pos[i]=0;
		int mnp=0;
		for(i=1;i<=m;i++){
			mnp=0;
			for(j=1;j<=n;j++)
				if(b[j][pos[j]+1]<b[mnp][pos[mnp]+1]) mnp=j;
			pos[mnp]++;
		}
		for(i=1;i<=n;i++){
			l[i]=0;r[i]=m+1;
		}
		for(i=1;i<=m;i++){
			bool f=0;
			for(j=1;j<=n;j++){
				if(!f&&l[j]<pos[j]){
					l[j]++;
					ans[j][i]=b[j][l[j]];
					f=1;
				}
				else{
					r[j]--;
					ans[j][i]=b[j][r[j]];
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++) cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}