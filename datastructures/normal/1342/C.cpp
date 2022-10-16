#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define int long long
using namespace std;
int t,a,b,q,l,r,sum[40005];
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		for (int i=1;i<=a*b;i++)sum[i]=sum[i-1]+(i%a%b!=i%b%a);
		int n=a*b;
		cin>>q;
		while(q--){
			cin>>l>>r;
			cout<<(r/n*sum[n]+sum[r%n])-((l-1)/n*sum[n]+sum[(l-1)%n])<<' ';
		}
		cout<<endl;
	}
	return 0;
}