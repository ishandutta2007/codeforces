#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
int a[2022];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>A;
	for(int i=n;i!=1;i-=2){
		int p1,p2;
		for(R j=1;j<=i;j++){
			if(a[j]==i){
				p1=j;
			}else if(a[j]==i-1){
				p2=j;
			}
		}
		if((p1&1)==0||(p2&1)==1){
			cout<<-1<<endl;
			return;
		}
		A.push_back(p1);
		reverse(a+1,a+1+p1);
		if(p2<p1){
			p2=p1-p2+1;
		}
		A.push_back(p2-1);
		reverse(a+1,a+p2);
		A.push_back(p2+1);
		reverse(a+1,a+p2+2);
		A.push_back(3);
		reverse(a+1,a+4);
		A.push_back(i);
		reverse(a+1,a+i+1);
	}
	cout<<A.size()<<endl;
	for(vector<int>::iterator T=A.begin();T!=A.end();T++){
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