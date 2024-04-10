#include<bits/stdc++.h>
using namespace std;
 
inline bool p(int x) {
	for (int i=2; i*i<=x; i++)
		if(x%i==0)
			return false;
	return true;
}
 
int main(){
	int n; cin>>n;
	int m=n;
	while(!p(m)) m++;
	cout<<m<<"\n";
	for(int i=1; i<=n; i++)
		cout<<i<<" "<<i%n+1<<"\n";
	for(int i=1; i<=m-n; i++)
		cout<<i<<" "<<i+n/2<<"\n";
	return 0;
}