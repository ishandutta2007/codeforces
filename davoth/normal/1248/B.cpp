#include <bits/stdc++.h>
using namespace std;
int main(){
	/*int qu;
	cin >> qu;
	while(qu--){
		int n;
		cin >> n;
		int p[n];
		for(int i=0; i<n; i++) cin >> p[i];
		int m;
		cin >> m;
		int q[m];
		for(int i=0; i<m; i++) cin >> q[i];
		long long pc=0,qc=0;
		for(int i=0; i<n; i++){
			if(p[i]%2==0) pc++;
		}
		for(int i=0; i<m; i++) if(q[i]%2==0) qc++;
		cout << (n-pc)*(m-qc)+pc*qc << '\n';
	}*/
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	long long l=0,r=n-1,x=0,y=0;
	while(r-l>=1){
		y+=a[r--];
		x+=a[l++];
	}
	if(r==l) y+=a[r];
	cout << x*x+y*y;
	return 0;
}