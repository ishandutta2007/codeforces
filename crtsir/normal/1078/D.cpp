#include<bits/stdc++.h>
using namespace std;
int n,a[300003];
int l[19][300003],r[19][300003],st[2][19][300003],lg[300003],al[300003],ar[300003],ans[3000003];
int main(){
//	freopen("sn.in","r",stdin);
//	freopen("sn.out","w",stdout);
	lg[1]=0;
	for(int i=2;i<300003;i++)
		lg[i]=lg[i>>1]+1;
	cin>>n;
	if(n==1){cout<<0;return 0;}
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i+n]=a[i];
		a[i+n+n]=a[i];
	}
	for(int i=0;i<3*n;i++)
		l[0][i]=max(0,i-a[i]),
		r[0][i]=min(3*n-1,i+a[i]);
	for(int i=1;i<19;i++){
		for(int j=0;j<3*n;j++)
			st[0][0][j]=l[i-1][j];
		for(int j=0;j<3*n;j++)
			st[1][0][j]=r[i-1][j];
		for(int j=1;j<19;j++)
			for(int k=0;k<=3*n-(1<<j);k++)
				st[0][j][k]=min(st[0][j-1][k],st[0][j-1][k+(1<<j-1)]);
		for(int j=1;j<19;j++)
			for(int k=0;k<=3*n-(1<<j);k++)
				st[1][j][k]=max(st[1][j-1][k],st[1][j-1][k+(1<<j-1)]);
		for(int j=0;j<3*n;j++){
			l[i][j]=min(st[0][lg[r[i-1][j]-l[i-1][j]+1]][l[i-1][j]],st[0][lg[r[i-1][j]-l[i-1][j]+1]][r[i-1][j]-(1<<lg[r[i-1][j]-l[i-1][j]+1])+1]);
			r[i][j]=max(st[1][lg[r[i-1][j]-l[i-1][j]+1]][l[i-1][j]],st[1][lg[r[i-1][j]-l[i-1][j]+1]][r[i-1][j]-(1<<lg[r[i-1][j]-l[i-1][j]+1])+1]);
		}
	}
	for(int i=n;i<n+n;i++)
		al[i]=i,ar[i]=i;
	for(int i=18;i>=0;i--){
		for(int j=0;j<3*n;j++)
			st[0][0][j]=l[i][j];
		for(int j=0;j<3*n;j++)
			st[1][0][j]=r[i][j];
		for(int j=1;j<19;j++)
			for(int k=0;k<=3*n-(1<<j);k++)
				st[0][j][k]=min(st[0][j-1][k],st[0][j-1][k+(1<<j-1)]);
		for(int j=1;j<19;j++)
			for(int k=0;k<=3*n-(1<<j);k++)
				st[1][j][k]=max(st[1][j-1][k],st[1][j-1][k+(1<<j-1)]);
		for(int j=n;j<n+n;j++){
			int nl=min(st[0][lg[ar[j]-al[j]+1]][al[j]],st[0][lg[ar[j]-al[j]+1]][ar[j]-(1<<lg[ar[j]-al[j]+1])+1]);
			int nr=max(st[1][lg[ar[j]-al[j]+1]][al[j]],st[1][lg[ar[j]-al[j]+1]][ar[j]-(1<<lg[ar[j]-al[j]+1])+1]);
			if(nr-nl+1<n)
				ans[j]|=(1<<i),al[j]=nl,ar[j]=nr;
		}
	}
	for(int i=n;i<n+n;i++)
		cout<<ans[i]+1<<' ';
}