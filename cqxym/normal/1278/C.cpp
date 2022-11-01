#include<iostream>
#include<map>
using namespace std;
#define R register int
map<int,int>P,Q;
short c[100001];
inline void Max(int &x,int y,int z){
	if(y!=0&&z!=0&&y+z>x){
		x=y+z;
	}
}
inline void Solve(){
	P.clear();
	Q.clear();
	int k,x,y,s=0;
	cin>>k;
	for(R i=1;i<=k;i++){
		cin>>x;
		if((x&1)==0){
			x=-1;
		}
		s+=x;
		P[s]=i;
	}
	s=0;
	for(R i=1;i<=k;i++){
		cin>>x;
		if((x&1)==0){
			c[k-i+1]=-1;
		}else{
			c[k-i+1]=1;
		}
	}
	for(R i=1;i<=k;i++){
		s+=c[i];
		Q[s]=i;
	}
	s=P[0]+Q[0];
	for(R i=1;i<=k;i++){
		Max(s,P[i],Q[-i]);
		Max(s,P[-i],Q[i]);
	}
	cout<<(k<<1)-s<<endl;
}
int main(){
	int n;
	cin>>n;
	for(R i=0;i<n;i++){
		Solve();
	}
	return 0;
}