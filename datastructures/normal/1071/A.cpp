#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int a,b,k,n,m;
int book[1000005];
int qwq(int a,int d){
	int num=0;
	for (int i=d;i>=1;i--)
		if (a>=i)a-=i,book[i]=1,num++;
	return num;
}
signed main(){
	cin>>a>>b;
	while(k*(k+1)/2<=(a+b))k++;
	k--;
	n=qwq(a,k);
	m=k-n;
	cout<<n<<endl;
	for (int i=1;i<=k;i++)
		if (book[i]==1)cout<<i<<' ';
	cout<<endl;
	cout<<m<<endl;
	for (int i=1;i<=k;i++)
		if (book[i]==0)cout<<i<<' ';
	cout<<endl;
	return 0;
}