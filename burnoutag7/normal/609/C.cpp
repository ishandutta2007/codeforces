#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

const int N=100010;
int a[N],n;
int x;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		x+=a[i];
	}
	int p=x/n;
	int q=x%n;
	q=n-q;
	int res=0;
	for(int i=0;i<n;i++){
		res+=max(0,a[i]-(p+(i>=q?1:0)));
	}
	cout<<res;
	return 0;
}