#include<bits/stdc++.h>
using namespace std;
long long n,a[100009],ret=1;map<long long,long long>M;
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<3;i++){
		long long G=0;for(int j=0;j<n;j++){if(a[i]==a[j])G++;}
		ret*=(G-M[a[i]]);M[a[i]]++;ret/=M[a[i]];
	}
	cout<<ret<<endl;
	return 0;
}