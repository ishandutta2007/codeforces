#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long LL;
using namespace std;


int main(){
	int n,k;
	LL b;
	cin >> n >> k >> b;
	LL a[n];
	LL c[n];
	for(int i=0;i<n;i++)cin >> a[i];
	n--;
	for(int i=0;i<n;i++)c[i]=a[i];
	sort(c,c+n);
	LL SK=0;
	for(int i=n-1;i>=n-k;i--)SK+=c[i];
	if(SK<=b){
		cout << n+1;
		return 0;
	}
	LL last=c[n-k];
	for(int i=0;i<n;i++){
		bool ok=false;
		if(a[i]>=last){
			ok=true;
		}
		else{
			if(SK-last+a[i]>b)ok=true;
		}
		if(ok){
			cout << i+1;
			return 0;
		}
	}
}