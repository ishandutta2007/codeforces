#include<iostream>
using namespace std;
long long a[2000000],b[2000000],n,m,u[200000],v[200000],r,s;
int main(){
	cin>>n>>m;r=n;s=n;
	for(int i=0;i<m;i++){
		if(i)cout<<' ';
		cin>>a[i]>>b[i];
		if(u[a[i]]==0){u[a[i]]=1;r--;}
		if(v[b[i]]==0){v[b[i]]=1;s--;}
		cout<<r*s;
	}
	cout<<endl;
	return 0;
}