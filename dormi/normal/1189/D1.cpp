#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int deg[100001];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}