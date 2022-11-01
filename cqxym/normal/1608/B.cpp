#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
int f[100000];
inline void Solve(){
	int n,a,b,t;
	cin>>n>>a>>b;
	bool tag=false;
	if(a<b){
		t=a;
		a=b;
		b=t;
		tag=true;
	}
	if(b<a-1||(a<<1|(a==b))>=n){
		cout<<-1<<endl;
		return;
	}
	for(R i=0;i!=a;i++){
		f[i<<1]=i+1<<1;
		f[i<<1|1]=i<<1|1;
	}
	if(a==b+1){
		for(R i=a<<1;i!=n;i++){
			f[i]=i+1;
		}
		if(tag==true){
			for(R i=0;i!=n;i++){
				f[i]=n-f[i]+1;
			}
		}
	}else{
		f[a<<1]=a+1<<1;
		f[a<<1|1]=a<<1|1;
		reverse(f,f+(a+1<<1));
		for(R i=a+1<<1;i!=n;i++){
			f[i]=i+1;
		}
	}
	for(R i=0;i!=n;i++){
		cout<<n-f[i]+1<<' ';
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