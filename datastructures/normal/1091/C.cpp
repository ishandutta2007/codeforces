#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,a[100005],tot;
int work(int x){
	int num=n/x;
	return num*(num-1)/2*x+num;
}
signed main(){
	cin>>n;
	for (int i=1;i*i<=n;i++)
		if (n%i==0){
			a[++tot]=work(i);
			if (i*i!=n)a[++tot]=work(n/i);
		}
	sort(a+1,a+1+tot);
	for (int i=1;i<=tot;i++)printf("%lld ",a[i]);
	cout<<endl;
	return 0;
}