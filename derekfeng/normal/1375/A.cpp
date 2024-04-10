#include<bits/stdc++.h>
using namespace std;
int T,n,a[103],b[103][2];
int f[103][53][53][2];
void solve(){
	memset(f,-1,sizeof(f));
	cin>>n;
	int M=(n-1)/2;
	for(int i=0;i<n;i++)cin>>a[i],b[i][0]=-abs(a[i]),b[i][1]=abs(a[i]);
	f[0][0][0][0]=f[0][0][0][1]=1;
	for(int i=1;i<n;i++)
		for(int j=0;j<=(n-1)/2;j++)
			for(int k=0;k<=(n-1)/2;k++)
				for(int l=0;l<2;l++)if(f[i-1][j][k][l]>0)
					for(int p=0;p<2;p++){
						int f1=0,f2=0;
						if(b[i-1][l]<=b[i][p]&&j!=M)f1=1;
						if(b[i-1][l]>=b[i][p]&&k!=M)f2=1;
						f[i][j+f1][k+f2][p]=1;
					}
	int B=(n-1)/2,C=(n-1)/2,D;
	if(f[n-1][(n-1)/2][(n-1)/2][0])D=0;
	else D=1;
	vector<int>res;
	res.push_back(b[n-1][D]);
//	cout<<B<<" "<<C<<" "<<D<<"\n";
	for(int i=n-1,ok=1;i>0;ok=1,i--)
		for(int j=0;j<=(n-1)/2&&ok;j++)
			for(int k=0;k<=(n-1)/2&&ok;k++)
			for(int l=0;l<2&&ok;l++)if(f[i-1][j][k][l]>0){
				int f1=0,f2=0;
				if(b[i-1][l]<=b[i][D]&&j!=M)f1=1;
				if(b[i-1][l]>=b[i][D]&&k!=M)f2=1;
				if(B==f1+j&&C==f2+k)B=j,C=k,D=l,ok=0,res.push_back(b[i-1][l]);
			}
	for(int i=n-1;i>=0;i--)cout<<res[i]<<" ";
	puts("");
}
int main(){
	cin>>T;
	while(T--)solve();
}