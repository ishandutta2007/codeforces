#include<iostream>
using namespace std;
int vis[100005];
int main() {
	int n,m,z;
	cin >> n >> m >> z;
	for (int i=n;i<=z;i+=n) 
	    vis[i]=1;
	int ans=0;
	for (int i=m;i<=z;i+=m) 
	    if (vis[i]) ans++;
	cout << ans;
	return 0;
}