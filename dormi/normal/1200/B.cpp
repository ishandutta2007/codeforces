#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int cur;
		cin>>cur;
		int a;
		bool work=true;
		for(int i=1;i<n;i++){
			cin>>a;
			int mi=max(0,a-k);
			m+=cur-mi;
			if(m<0){
				work=false;
			}
			cur=a;
		}
		if(work)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}