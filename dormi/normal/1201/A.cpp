#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int am=0;
	int po;
	for(int i=0;i<m;i++){
		int ans[5]={ };
		cin>>po;
		for(int j=0;j<n;j++){
			ans[arr[j][i]-'A']+=1;
		}
		sort(ans,ans+5);
		am+=ans[4]*po;
	}
	printf("%d\n",am);
	return 0;
}