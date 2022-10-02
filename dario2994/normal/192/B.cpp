#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)cin >> a[i];
	int b[n];
	b[n-1]=a[n-1];
	b[n-2]=min(a[n-2],a[n-1]);
	for(int i=n-3;i>=0;i--)b[i]=min(a[i],max(b[i+1],b[i+2]));
	//for(int i=0;i<n;i++)cout << b[i] << " ";
	cout << b[0];
}