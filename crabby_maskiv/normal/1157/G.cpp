#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
bool opn[N],opm[N];
bool a[N][N];
bool ok(){
	int i,j,k;
	bool flag=1;
	for(i=1;i<=n;i++){
		if(i>1&&a[i-1][m]==0){
			for(j=1;j<=m;j++)
				if(!a[i][j]) break;
			if(j>m){
				opn[i]=1;
				for(j=1;j<=m;j++) a[i][j]=0;
			}
		}
		for(j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			int pi=i,pj=j;
			pj--;
			if(!pj){
				pi--;
				pj=m;
			}
			if(a[pi][pj]>a[i][j]){
				if(opn[i]) flag=0;
				opn[i]^=1;
				for(k=1;k<=m;k++) a[i][k]^=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			int pi=i,pj=j;
			pj--;
			if(!pj){
				pi--;
				pj=m;
			}
			if(a[pi][pj]>a[i][j]) flag=0;
		}
	}
	if(flag) return 1;
	for(i=1;i<=n;i++){
		if(opn[i]){
			for(j=1;j<=m;j++) a[i][j]^=1;
			opn[i]=0;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) cin>>a[i][j];
	for(i=1;i<=m;i++){
		if(a[1][i]){
			for(j=1;j<=n;j++) a[j][i]^=1;
			opm[i]=1;
		}
	}
	if(ok()){
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++) cout<<opn[i];
		cout<<endl;
		for(i=1;i<=m;i++) cout<<opm[i];
		return 0;
	}
	for(i=m;i;i--){
		if(!a[1][i]){
			for(j=1;j<=n;j++) a[j][i]^=1;
			opm[i]^=1;
		}
		if(ok()){
			cout<<"YES"<<endl;
			for(j=1;j<=n;j++) cout<<opn[j];
			cout<<endl;
			for(j=1;j<=m;j++) cout<<opm[j];
			return 0;	
		}
	}
	cout<<"NO";
	return 0;
}