#include<iostream>
using namespace std;
#define R register int
int d[1001];
inline void Solve(){
	int n,x,a,b;
	scanf("%d%d",&n,&x);
	for(R i=1;i<=n;i++){
		d[i]=0;
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&a,&b);
		d[a]++;
		d[b]++;
	}
	if(d[x]<=1||(n&1)==0){
		cout<<"Ayush";
	}else{
		cout<<"Ashish";
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