#include<iostream>
#include<queue>
using namespace std;
#define R register int
int a[100000];
inline void Solve(){
	int n,k;
	cin>>n>>k;
	int l=n-1-k,r=k;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	if(l+1>=r){
		puts("YES");
	}else{
		priority_queue<int>Q;
		for(R i=0;i<=l;i++){
			Q.push(a[i]);
		}
		for(R i=r;i!=n;i++){
			Q.push(a[i]);
		}
		for(R i=n-1;i>=r;i--){
			a[i]=Q.top();
			Q.pop();
		}
		for(R i=l;i!=-1;i--){
			a[i]=Q.top();
			Q.pop();
		}
		for(R i=1;i!=n;i++){
			if(a[i]<a[i-1]){
				puts("No");
				return;
			}
		}
		puts("Yes");
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