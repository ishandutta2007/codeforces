#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int n,x,a;
long long sum=0;
int main(){
	cin>>n>>x;
	for (int i=0;i<n;i++){
		scanf("%d",&a);
		sum+=a; 
	}
	if (sum+n==x+1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}