#include<bits/stdc++.h>
#define ui unsigned int
using namespace std;

ui N,P,Q; 

ui gcd(ui a,ui b){
	return b?gcd(b,a%b):a;
}
vector<ui> a,b;
ui calc(ui i){
	a.clear(),b.clear();
	for(ui j=1;j<=i;j++)
		a.push_back(N-j+1),b.push_back(j);
	for(ui j=0;j<i;j++)
	for(ui k=0;k<i;k++){
		ui d=gcd(a[j],b[k]);a[j]/=d,b[k]/=d;
	}
	ui ans=1;
	for(ui j=0;j<i;j++) ans*=a[j];
	return ans;
}

ui C[133];

int main(){
	scanf("%d%d%d",&N,&P,&Q);P=min(P,N-1);
	for(ui i=0;i<=P;i++)
		C[i]=calc(i);
	ui ans=0;
	for(ui i=1;i<=Q;i++){
		ui powi=1,Ri=0;
		for(ui j=0;j<=P;j++)
			powi*=i,Ri+=C[j]*powi;
		ans^=Ri;
	}
	printf("%u",ans);
}