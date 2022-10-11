#include<bits/stdc++.h>
using namespace std;
int n,a[100009];long long ret=0;
bool solve(int p){
	if(p==1)return true;
	for(int i=1;i<=30;i++){
		if((1<<i)==p)return true;
	}
	return false;
}
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<=30;i++){
		int L=(1<<i);
		for(int j=0;j<n;j++){
			int pos1=lower_bound(a,a+n,L-a[j])-a;
			int pos2=lower_bound(a,a+n,L-a[j]+1)-a;
			ret+=(long long)(pos2-pos1);
		}
	}
	for(int i=0;i<n;i++){
		if(solve(a[i])==true)ret--;
	}
	cout<<ret/2<<endl;
	return 0;
}