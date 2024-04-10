#include <bits/stdc++.h>
using namespace std;
long long int dp[1000001];
bool check[1000001];
long long int N;
int main() {
	long long int m, a, b;
	N=1000000;
	cin>>m>>a>>b;
	dp[0]=1;
	check[0]=true;
	for(long long int i=1; i<=(min(m, N)); i++){
		int cnt=0;
		if(i-a<0 ){
			dp[i]=dp[i-1];
			continue;
		}
		if(check[i-a]==false){
			dp[i]=dp[i-1];
			continue;
		}
		check[i]=true;
		cnt++;
		queue<long long int>q;
		q.push(i);
		while(!q.empty()){
			long long int x=q.front();
			q.pop();
			check[x]=true;
			if(x-b>=0 && check[x-b]==false){
				cnt++;
				q.push(x-b);
			}
			if(x+a<=i && check[x+a]==false){
				cnt++;
				q.push(x+a);
			}
		}
		dp[i]=dp[i-1]+cnt;
	}
	
	long long int ans=0;
	if(m<=1000000){
		for(int i=0; i<=m; i++){
			ans+=dp[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=0; i<=1000000; i++){
		ans+=dp[i];
	}
	
	long long int val=__gcd(a, b);
	long long int index1=-1;
	for(long long int i=1000001; i<=m; i++){
		if(i%val==0){
			index1=i;
			break;
		}
	}
	
	long long int index2=-1;
	for(long long int i=m; i>=1000001; i--){
		if(i%val==0){
			index2=i;
			break;
		}
	}
	
	if(index1==-1 || index2==-1){
		for(long long int i=1000001; i<=m; i++){
			ans=ans+(i/val)+1;
		}
		cout<<ans;
		return 0;
	}
	
	for(long long int i=1000001; i<index1; i++){
		ans=ans+(i/val)+1;
	}
	
	for(long long int i=index2; i<=m; i++){
		ans=ans+(i/val)+1;
	}
	
	if(index1==index2){
		cout<<ans;
		return 0;
	}
	long long int val1=(index1/val);
	long long int val2=(index2/val)-1;
	ans=ans+val*(val2-val1+1);
	ans=ans+((val1+val2)*(val2-val1+1)*val)/2;
	cout<<ans;
	return 0;
}