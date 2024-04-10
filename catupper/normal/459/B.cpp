#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long Int;
Int a[216000], n;


int main(){
	cin >> n;
	for(Int i = 0;i < n;i++)cin >> a[i];
	sort(a, a + n);
	Int mi = a[0], ma = a[n - 1];
	if(mi == ma){
		cout << 0 << " " << n*(n-1)/2 << endl;
		return 0;
	}                       	
	Int cntmin = 0, cntmax = 0;
	for(Int i = 0;i < n;i++){
		if(a[i] == mi)cntmin++;
		if(a[i] == ma)cntmax++;
	}
	cout << ma - mi << " " << cntmin * cntmax << endl;
	return 0;
}