#include<iostream>
#include<set>
using namespace std;
#define R register int
inline void Solve(){
	int n,a;
	cin>>n;
	set<int>S;
	for(R i=0;i!=n;i++){
		cin>>a;
		if(S.count(a)==0){
			S.insert(a);
		}else{
			S.insert(-a);
		}
	}
	cout<<S.size()<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}