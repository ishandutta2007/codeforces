#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
struct Player{
	int ValA,ValB,Id;
	inline friend bool operator<(Player A,Player B){
		return A.ValB<B.ValB;
	}
}p[100000];
int a[100000],maxA[100000];
inline void Solve(){
	int n,q;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>p[i].ValA;
		p[i].Id=i;
	}
	for(R i=0;i!=n;i++){
		cin>>p[i].ValB;
	}
	sort(p,p+n);
	maxA[0]=p[0].ValA;
	for(R i=1;i!=n;i++){
		maxA[i]=maxA[i-1];
		if(p[i].ValA>maxA[i]){
			maxA[i]=p[i].ValA;
		}
	}
	a[p[n-1].Id]=1;
	q=p[n-1].ValA;
	for(R i=n-2;i!=-1;i--){
		if(maxA[i]>q){
			a[p[i].Id]=1;
			if(p[i].ValA<q){
				q=p[i].ValA;
			}
		}else{
			a[p[i].Id]=0;
		}
	}
	for(R i=0;i!=n;i++){
		cout<<a[i];
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