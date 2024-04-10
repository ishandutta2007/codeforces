#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define R register int
int a[1000];
vector<int>B[1000];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	B[0].clear();
	B[0].push_back(1);
	stack<int>S;
	S.push(0);
	for(int i=1;i!=n;i++){
		if(a[i]==1){
			S.push(i);
			B[i]=B[i-1];
			B[i].push_back(1);
		}else{
			while(a[i]!=a[S.top()]+1){
				S.pop();
			}
			B[i]=B[S.top()];
			B[i].back()=a[i];
			S.pop();
			S.push(i);
		}
	}
	for(R i=0;i!=n;i++){
		cout<<B[i][0];
		for(vector<int>::iterator T=B[i].begin()+1;T!=B[i].end();T++){
			cout<<'.'<<*T;
		}
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}