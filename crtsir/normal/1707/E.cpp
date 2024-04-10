#include<bits/stdc++.h>
using namespace std;
int l[40][20][100003],r[40][20][100003],n,q,a[100003],lg[100003];
int main(){
	for(int i=2;i<100003;i++)
		lg[i]=lg[i>>1]+1;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>a[i],a[i]--;
	for(int i=0;i<n;i++)
		l[0][0][i]=a[i],
		r[0][0][i]=a[i];
	for(int i=1;i<20;i++)
		for(int j=0;j<=n-(1<<i);j++)
			l[0][i][j]=min(l[0][i-1][j],l[0][i-1][j+(1<<i-1)]),
			r[0][i][j]=max(r[0][i-1][j],r[0][i-1][j+(1<<i-1)]);
	for(int i=1;i<40;i++)
		for(int j=0;j<20;j++)
			for(int k=0;k<=(n-(1<<j));k++){
				l[i][j][k]=min(l[i-1][lg[r[i-1][j][k]-l[i-1][j][k]+1]][l[i-1][j][k]],l[i-1][lg[r[i-1][j][k]-l[i-1][j][k]+1]][r[i-1][j][k]-(1<<lg[r[i-1][j][k]-l[i-1][j][k]+1])+1]);
				r[i][j][k]=max(r[i-1][lg[r[i-1][j][k]-l[i-1][j][k]+1]][l[i-1][j][k]],r[i-1][lg[r[i-1][j][k]-l[i-1][j][k]+1]][r[i-1][j][k]-(1<<lg[r[i-1][j][k]-l[i-1][j][k]+1])+1]);
			}
	while(q--){
		int L,R,tL,tR;
		cin>>L>>R;L--;R--;
		if(L==0&&R==n-1){
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		for(int i=39;i>=0;i--)
			if(min(l[i][lg[R-L+1]][L],l[i][lg[R-L+1]][R-(1<<lg[R-L+1])+1])!=0||max(r[i][lg[R-L+1]][L],r[i][lg[R-L+1]][R-(1<<lg[R-L+1])+1])!=n-1)
				tL=min(l[i][lg[R-L+1]][L],l[i][lg[R-L+1]][R-(1<<lg[R-L+1])+1]),
				tR=max(r[i][lg[R-L+1]][L],r[i][lg[R-L+1]][R-(1<<lg[R-L+1])+1]),
				L=tL,R=tR,ans+=(1ll<<i);
		if(min(l[0][lg[R-L+1]][L],l[0][lg[R-L+1]][R-(1<<lg[R-L+1])+1])==0&&max(r[0][lg[R-L+1]][L],r[0][lg[R-L+1]][R-(1<<lg[R-L+1])+1])==n-1)
			cout<<ans+1<<'\n';
		else
			cout<<"-1\n";
	}
}