#include<iostream>
#include<vector>
using namespace std;
#define R register int
inline void Solve(){
	long long p,d;
	cin>>p;
	d=p;
	int q;
	cin>>q;
	if(p%q!=0){
		cout<<p<<endl;
		return;
	}
	vector<int>V,P;
	p/=q;
	for(int i=2;i*i<=q;i++){
		if(q%i==0){
			V.push_back(i);
			int ct=1;
			while(p%i==0){
				ct++;
				p/=i;
			}
			P.push_back(ct);
			while(q%i==0){
				q/=i;
			}
		}
	}
	if(q!=1){
		V.push_back(q);
		int ct=1;
		while(p%q==0){
			ct++;
			p/=q;
		}
		P.push_back(ct);
	}
	long long ans=1e18;
	for(R i=0;i!=V.size();i++){
		long long cur=1;
		for(R j=0;j!=P[i];j++){
			cur*=V[i];
		}
		if(cur<ans){
			ans=cur;
		}
	}
	cout<<d/ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}