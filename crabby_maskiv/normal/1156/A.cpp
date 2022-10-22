#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m,k;
int a[N];
int main(){
	int i,j;
	cin>>n;
	int cnt=0;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<n;i++){
		if(a[i]==2&&a[i+1]==3){
			cout<<"Infinite";
			return 0;
		} 
		if(a[i]==3&&a[i+1]==2){
			cout<<"Infinite";
			return 0;
		} 
		if(a[i]==1&&a[i+1]==3)
			cnt+=4;
		if(a[i]==3&&a[i+1]==1)
			cnt+=4;
		if(a[i]==2&&a[i+1]==1)
			cnt+=3;
		if(a[i]==1&&a[i+1]==2)
			cnt+=3;
		if(i<n-1&&a[i]==3&&a[i+1]==1&&a[i+2]==2)
			cnt--; 
	}
	cout<<"Finite"<<endl;
	cout<<cnt;
	return 0;
}