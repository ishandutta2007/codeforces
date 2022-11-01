#include<queue>
#include<stack>
#include<map>
#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,sum,ans,emp[100010],out;
int main(){
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>emp[i];
		sum+=emp[i];
	}
	ans=(sum+n-2)/(n-1);
	for(int i=1;i<=n;i++){
		if(emp[i]>ans){
			ans=emp[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}