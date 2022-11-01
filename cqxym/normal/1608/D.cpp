#include<iostream>
using namespace std;
#define R register int
#define L long long
#define P 998244353
char s[100000][2];
inline int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
inline int GetC(int n,int m){
	int A=1,B=1;
	for(R i=n;i!=n-m;i--){
		A=(L)A*i%P;
	}
	for(R i=2;i<=m;i++){
		B=(L)B*i%P;
	}
	return(L)A*GetInv(B)%P;
}
int main(){
	int n,ct=0,ctb=0,f=1,bf=1,wf=1;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>s[i][0]>>s[i][1];
		ct+=(s[i][0]=='?')+(s[i][1]=='?');
		ctb+=(s[i][0]=='B')+(s[i][1]=='B');
		if(s[i][0]=='?'&&s[i][1]=='?'){
			f<<=1;
			if(f>P){
				f-=P;
			}
		}else if(s[i][0]==s[i][1]){
			f=0;
		}
		if(s[i][0]=='W'||s[i][1]=='B'){
			bf=0;
		}
		if(s[i][0]=='B'||s[i][1]=='W'){
			wf=0;
		}
	}
	if(ctb>n||ctb+ct<n){
		cout<<0;
		return 0;
	}
	f=GetC(ct,n-ctb)-f;
	if(f<0){
		f+=P;
	}
	f+=bf+wf;
	if(f>=P){
		f-=P;
	}
	cout<<f;
	return 0;
}