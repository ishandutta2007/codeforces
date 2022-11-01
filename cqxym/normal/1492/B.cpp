#include<iostream>
#include<vector>
using namespace std;
#define R register int
int p[100000],b[100001];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>p[i];
	}
	b[0]=p[0];
	for(R i=1;i!=n;i++){
		b[i]=max(b[i-1],p[i]);
	}
	vector<int>V,D;
	for(int i=0;i!=n;i++){
		if(b[i]==p[i]){
			V.push_back(i);
		}
	}
	int lt=n,s=V.size();
	for(R i=s-1;i!=-1;i--){
		for(R j=V[i];j!=lt;j++){
			D.push_back(p[j]);
		}
		lt=V[i];
	}
	for(vector<int>::iterator T=D.begin();T!=D.end();T++){
		cout<<*T<<' ';
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}