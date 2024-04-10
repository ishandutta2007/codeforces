#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int t,n,a[200005];
int c[200005],tot;
bool palin(){
	for (int l=1,r=tot;l<=r;l++,r--)
		if (c[l]!=c[r])return 0;
	return 1; 
}
bool check(int x){
	tot=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=x)c[++tot]=a[i];
	return palin();
}
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		int l=1,r=n;
		while(l<=r){
			if (a[l]!=a[r])break;
			l++,r--;
		}
		if (l>r)puts("YES");
		else if (check(a[l])||check(a[r]))puts("YES");
		else puts("NO");	
	}
	return 0;
}