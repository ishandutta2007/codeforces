#include<iostream>
#include<map>
using namespace std;
#define R register int
inline void Solve(){
	int n,x,d;
	map<int,int>Q;
	cin>>n;
	d=n<<1;
	for(R i=0;i!=n;i++){
		cin>>x;
		if(Q.count(x)!=0&&i-Q[x]<d){
			d=i-Q[x];
		}
		Q[x]=i;
	}
	if(d>n){
		cout<<-1<<endl;
	}else{
		cout<<n-d<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}