#include<iostream>
#include<vector>
using namespace std;
#define R register int
int C[131];
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
inline int GetC(int n,int m){
	vector<int>A;
	for(int i=n;i!=n-m;i--){
		A.push_back(i);
	}
	for(R i=2;i<=m;i++){
		n=i;
		for(vector<int>::iterator T=A.begin();T!=A.end();T++){
			int g=Gcd(*T,n);
			n/=g;
			*T/=g;
		}
	}
	n=1;
	for(vector<int>::iterator T=A.begin();T!=A.end();T++){
		n*=*T;
	}
	return n;
}
int main(){
	C[0]=1;
	int n,p,q,ans=0,cur,s;
	cin>>n>>p>>q;
	if(n-1<p){
		p=n-1;
	}
	for(R i=1;i<=p;i++){
		C[i]=GetC(n,i);
	}
	for(R i=1;i<=q;i++){
		cur=0;
		s=1;
		for(R j=0;j<=p;j++){
			s*=i;
			cur+=s*C[j];
		}
		ans^=cur;
	}
	cout<<(unsigned int)ans;
	return 0;
}