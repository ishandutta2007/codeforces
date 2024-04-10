#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int k;
int a[2005];
void work(int len,int s){
	int qwq=min(s,1000000ll);
	a[len]-=qwq;
	s-=qwq;
	len--;
	int t=s/len;
	for (int i=1;i<=len;i++)a[len-i+1]-=t;
	s-=t*len;
	for (int i=1;i<=s;i++)a[len-i+1]--;
	s=0;
	return;
}
signed main(){
	cin>>k;
	int n=2000;
	int s2=1000000-k%2000;
	a[n]=s2;
	int s1=(k+s2)/n;
	work(n-1,s2-s1);
	cout<<n<<endl;
	for (int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}