#include<bits/stdc++.h>
using namespace std;
int n,m;vector<int>a;
int main(){
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		while(n%i==0){a.push_back(i);n/=i;}
	}
	if(a.size()<m){cout<<"-1"<<endl;return 0;}
	int F=1;
	for(int i=0;i<m-1;i++){cout<<a[i]<<' ';}
	for(int i=m-1;i<a.size();i++)F*=a[i];
	cout<<F<<endl;
	return 0;
}