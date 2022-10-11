#include<iostream>
#include<algorithm>
using namespace std;
int t[200000],n,a;
int main(){
	cin>>n;for(int i=0;i<n;i++){cin>>a;t[a]++;}
	int maxn=1;
	for(int i=2;i<=199999;i++){
		int s=0;
		for(int j=i;j<=199999;j+=i)s+=t[j];
		maxn=max(maxn,s);
	}
	cout<<maxn<<endl;
	return 0;
}