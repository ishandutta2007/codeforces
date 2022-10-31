#include<iostream>
using namespace std;
bool dfs(int sum,int now,int num){
	if (sum==0){
		cout<<num<<endl;
		cout<<now<<' ';
		return 1;
	}
	for(int i=now+1;i<=sum;i++){
		bool flag=dfs(sum-i,i,num+1);
		if (flag) {
			if (now)
			cout<<now<<' ';
			return 1;
		}
	}
	return 0;
}
int main(){
	int n;
	cin>>n;
	bool flag=dfs(n,0,0);
	return 0;
}