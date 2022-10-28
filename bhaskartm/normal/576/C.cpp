#include <bits/stdc++.h>
#define L first.first
#define R first.second
#define ID second
using namespace std;
int n;
pair<pair<int,int>,int> a[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].L>>a[i].R;
		a[i].L/=1050;
		a[i].ID=i+1;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i].ID<<' ';
	}
	return 0;
}