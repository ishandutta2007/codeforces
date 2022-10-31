#include<iostream>
using namespace std;
	int sum[200];
	int n;
	int ans[200];
	bool print=false;
void dfs(int parts,int now){
	if (now==n+1&&(!print)){
		cout<<"YES"<<endl;
		cout<<parts<<endl;
		for(int i=1;i<=parts;i++){
			cout<<ans[i-1]+1<<' '<<ans[i]<<endl;
		}
		print=true;
	}
	for (int i=now;i<=n;i++){
		int temp=sum[i]-sum[now-1];
		if (temp!=0){
			ans[parts+1]=i;
			dfs(parts+1,i+1);
			if (print) return;
		}
	}
}
int main(){

	cin>>n;
	int data[200];
	for (int i=1;i<=n;i++){
		cin>>data[i];
	}
	if (n==1&&data[1]==0){
		cout<<"NO";
		return 0; 
	}else if (n==1&&data[1]!=0){
		cout<<"YES"<<endl;
		cout<<1<<endl;
		cout<<1<<' '<<1;
		return 0;
	}
	int parts=0;

	sum[0]=0;
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+data[i];
	}
	
	dfs(0,1);
	if (!print) cout<<"NO";
}