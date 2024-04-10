#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=20;
const long long mdn=1000003;
 
long long x[maxn][maxn];
 
long long qpow(long long bse,long long ex){
	if(ex==0) return 0;
	if(ex==1) return bse%mdn;
	long long ans=qpow(bse,ex/2);
	ans=(ans*ans)%mdn;
	if(ex%2) ans=(ans*bse)%mdn;
	return ans;
}
long long inv(long long x){
	return qpow(x,mdn-2);
}
int gauss(int n){
	int c=1;
	for(int i=1;i<=n;i++){
		int idx=0;
		for(int j=c;j<=n;j++)if(x[j][i]) idx=j;
		if(!idx)continue;
		for(int j=1;j<=n+1;j++)swap(x[c][j],x[idx][j]);
		for(int j=n+1;j>=i;j--)x[c][j]=(x[c][j]*inv(x[c][i]))%mdn;
		for(int j=c+1;j<=n;j++){
			for(int k=n+1;k>=i;k--)x[j][k]=(x[j][k]-(x[c][k]*x[j][i])%mdn+mdn)%mdn;
		}
		c++;
	}/*
	for(int i=1;i<=11;i++){
		for(int j=1;j<=12;j++)cout<<x[i][j]<<',';
		cout<<endl;
	}*/
	if(c<=n) return c;
	for(int i=n;i>=1;i--){
		for(int j=1;j<i;j++){
			x[j][n+1]=(x[j][n+1]-(x[j][i]*x[i][n+1])%mdn+mdn)%mdn;
		}
	}
	return -1;
}
 
int main(){
	int cup=1;
	for(int i=1;i<=50;i++){
		cout<<"? "<<i<<endl;
		fflush(stdout);
		long long ans;cin>>ans;
		x[cup][1]=1;
		for(int j=2;j<=11;j++){
			x[cup][j]=(x[cup][j-1]*i)%mdn;
		}
		x[cup][12]=ans;
		cup=gauss(11);
		
		if(cup==-1){
			for(int i=0;i<mdn;i++){
				long long ca=0,cpw=1;
				for(int j=1;j<=11;j++){
					ca=(ca+(cpw*x[j][12])%mdn+mdn)%mdn;
					cpw=(cpw*i)%mdn;
				}
				if(ca==0){
					cout<<"! "<<i;
					return 0;
				}
			}
			cout<<"! -1";
			return 0;
		}
	}
	//cout<<"! -1";
	return 0;
}