#include<iostream>
#include<queue> 
using namespace std;
int main(){
	int n,a,ans=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> >Q;
	long long h=0;
	for(register int i=n;i!=0;i--){
		cin>>a;
		if(h+a>-1){
			ans++;
			h+=a;
			Q.push(a);
		}else if(Q.empty()==false&&Q.top()<a){
			h+=a-Q.top();
			Q.pop();
			Q.push(a);
		}
	}
	cout<<ans;
	return 0;
}