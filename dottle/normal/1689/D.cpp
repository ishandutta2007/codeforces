#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

int dx[]={1,-1,1,-1},dy[]={1,1,-1,-1};
int impx[4],impy[4];
int a[N][N];
int n,m;

int dis(int a,int b,int c,int d){
	return abs(a-c)+abs(b-d);
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++)
			a[i][j+1]=s[j]=='B';
	}
	for(int i=0;i<4;i++)impx[i]=dx[i]*-1e6,impy[i]=dy[i]*-1e6;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]){
				for(int k=0;k<4;k++){
					if(i*dx[k]+j*dy[k]>impx[k]*dx[k]+impy[k]*dy[k])
						impx[k]=i,impy[k]=j;
				}
			}
	int resx=1,resy=1,nwr=1e9;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int nw=0;
			for(int k=0;k<4;k++)
				nw=max(nw,dis(i,j,impx[k],impy[k]));
			if(nw<nwr)resx=i,resy=j,nwr=nw;
		}
	cout<<resx<<' '<<resy<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}