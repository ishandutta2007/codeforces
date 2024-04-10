#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		int a,b,c;
		cin>>a>>b>>c;
		if(c%3==0){
			printf("%d\n",a);
		}
		else if(c%3==1){
			printf("%d\n",b);
		}
		else{
			printf("%d\n",a^b);
		}
	}
	return 0;
}