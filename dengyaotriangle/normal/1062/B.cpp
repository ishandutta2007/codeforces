#include<bits/stdc++.h>
using namespace std;

const int maxn=1000006;

bool ip[maxn];
int p[maxn];
int pc;
int m[maxn],mc;

bool isprime(int n){
	if(n<2) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}

int main(){
	memset(ip,1,sizeof(ip));
	ip[1]=0;
	for(long long i=2;i<maxn;i++){
		if(!ip[i]) continue;
		p[pc++]=i;
		for(long long j=i*i;j<maxn;j+=i) ip[j]=0;
	}
	int n;
	cin>>n;
	int a1=1,a2=0,ls=-1;
	bool as=1;
	for(int i=0;i<pc;i++){
		int ct=0;
		//if(p[i]>n) break;
		while(n%p[i]==0){
			n/=p[i];
			ct++;
		}
		if(ct!=0){
			a1*=p[i];
			m[mc++]=ct;
		}
	}
	cout<<a1<<' ';
	int d=0;
	while(1){
		bool fin=1;
		for(int i=0;i<mc;i++){
			if(m[i]!=1) fin=0;
		}
		if(fin){
			cout<<d;
			return 0;
		}
		bool is2=1;
		for(int i=0;i<mc;i++){
			if(m[i]%2) is2=0; 
		}
		if(is2){
			for(int i=0;i<mc;i++){
				m[i]/=2;
			}
			d++;
		}else{
			int mx=0;
			for(int i=0;i<mc;i++) mx=max(mx,m[i]);
			int sqn=0;
			for(int i=1;1;i*=2){
				sqn=i;
				if(i>=mx) break;
			}
			for(int i=0;i<mc;i++) m[i]=sqn;
			d++;
		}
	}
	return 0;
}