#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
const int maxm=2000026;

const long long p1=307;
const long long p2=100000223ll;

char x[maxn],y[maxm];
int n,m;
int c0=0,c1=0;

long long hsh[maxm];
long long pwr[maxm];

bool eql(int l1,int r1,int l2,int r2){
	return (hsh[r1]-(hsh[l1-1]*pwr[r1-l1+1])%p2+p2)%p2==(hsh[r2]-(hsh[l2-1]*pwr[r2-l2+1])%p2+p2)%p2;
}
int main(){
	cin>>x>>y;
	n=strlen(x);
	m=strlen(y);
	hsh[1]=y[0];
	pwr[0]=1;
	for(int i=1;i<=m+2;i++) pwr[i]=(pwr[i-1]*p1)%p2;
	for(int i=1;i<m;i++){
		hsh[i+1]=(hsh[i]*p1+y[i])%p2;
	}
	
	if(x[0]=='1'){
		for(int i=0;i<n;i++){
			if(x[i]=='0') x[i]='1';
			else x[i]='0';
		}
	}
	for(int i=0;i<n;i++){
		if(x[i]=='0') c0++;
		else c1++;
	}
	long long ans=0;
	for(int i=1;i<=m;i++){
		int ch=m-i*c0;
		if(ch<=0) continue;
		if(ch%c1) continue;
		int l1=ch/c1;
		int l0=1;
		bool ok=1;
		int c1l=-1;
		for(int j=0;j<n;j++){
			if(x[j]=='0'){
				if(l0+i-1>m){
					ok=0;
					break;
				}
				if(!eql(1,1+i-1,l0,l0+i-1)) ok=0;
				l0=l0+i;
			}else if(x[j]=='1'){
				if(l0+l1-1>m){
					ok=0;
					break;
				}
				if(c1l==-1){
					c1l=l0;
					l0=l0+l1;
				}else{
					if(!eql(c1l,c1l+l1-1,l0,l0+l1-1)) ok=0;
					l0=l0+l1;
				}
			}
		}
		if(i==l1&&eql(1,1+i-1,c1l,c1l+l1-1)) ok=0;
		if(ok) ans++;
	}
	cout<<ans;
	return 0;
}