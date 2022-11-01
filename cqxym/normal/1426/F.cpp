#include<iostream>
using namespace std;
#define R register int
#define P 1000000007
long long f[600001][3][4],p[200001];
int main(){
	string s="c";
	int n,ct=0;
	cin>>n;
	char c;
	for(R i=0;i!=n;i++){
		cin>>c;
		s+=c;
		ct+=c=='?';
	}
	p[0]=1;
	for(R i=1;i<=n;i++){
		p[i]=p[i-1]*3%P;
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=3;j++){
			for(R k=0;k!=4;k++){
				f[i][j][k]=f[i-1][j][k];
			}
		}
		if(s[i]=='a'){
			f[i][0][0]++;
		}else if(s[i]=='b'){
			f[i][1][0]+=f[i-1][0][0];
			f[i][1][1]+=f[i-1][0][1];
		}else if(s[i]=='c'){
			f[i][2][0]+=f[i-1][1][0];
			f[i][2][1]+=f[i-1][1][1];
			f[i][2][2]+=f[i-1][1][2];
		}else{
			f[i][0][1]++;
			for(R j=1;j!=3;j++){
				for(R k=1;k!=j+2;k++){
					f[i][j][k]+=f[i-1][j-1][k-1];
				}
			}
		}
		for(R j=0;j!=3;j++){
			for(R k=0;k!=4;k++){
				f[i][j][k]%=P;
			}
		}
	}
	long long ans=0;
	for(R i=0;i!=4&&i<=ct;i++){
		ans+=f[n][2][i]*p[ct-i]%P;
		ans%=P;
	}
	cout<<ans;
	return 0;
}