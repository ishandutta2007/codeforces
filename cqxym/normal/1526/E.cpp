#include<iostream>
using namespace std;
#define R register int
#define L long long
#define P 998244353
int pos[200000],rk[200001];
inline int GetC(int n,int m){
	int t1=1,t2=1,y=P-2;
	for(R i=2;i<=m;i++){
		t2=(L)t2*i%P;
	}
	for(R i=0;i!=m;i++){
		t1=(L)t1*(n-i)%P;
	}
	while(y!=0){
		if((y&1)==1){
			t1=(L)t1*t2%P;
		}
		y>>=1;
		t2=(L)t2*t2%P;
	}
	return t1;
}
int main(){
	int n,k,ct=1;
	cin>>n>>k;
	for(R i=0;i!=n;i++){
		cin>>pos[i];
		rk[pos[i]]=i+1;
	}
	for(R i=1;i!=n;i++){
		if(rk[pos[i-1]+1]>rk[pos[i]+1]){
			ct++;
		}
	}
	if(ct>k){
		cout<<0;
	}else{
		cout<<GetC(k+n-ct,n);
	}
	return 0;
}