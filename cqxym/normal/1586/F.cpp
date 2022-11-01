#include<iostream>
using namespace std;
#define R register int
inline int Pow(int a,int b){
	int res=1;
	for(R i=0;i!=b;i++){
		res*=a;
	}
	return res;
}
int S[1001];
int main(){
	int n,k,c=2,cur;
	cin>>n>>k;
	while(Pow(k,c)<n){
		c++;
	}
	cout<<c<<endl;
	cur=Pow(k,c);
	for(R i=1;i<=n;i++){
		S[i]=cur-i;
	}
	for(R i=1;i!=n;i++){
		for(R j=i+1;j<=n;j++){
			cur=1;
			int pw=1;
			while(cur<=c){
				if(S[i]/pw%k>S[j]/pw%k){
					cout<<cur<<' ';
					break;
				}
				cur++;
				pw*=k;
			}
		}
	}
	return 0;
}