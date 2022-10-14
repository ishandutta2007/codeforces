#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n%2==0){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		int arr[2*n];
		for(int i=1;i<=2*n;i+=2){
			arr[i/2]=((i/2)%2==0?i:i+1);
			arr[i/2+n]=((i/2)%2==0?i+1:i);
		}
		for(int i=0;i<2*n;i++){
			printf("%d ",arr[i]);
		}
	}
	return 0;
}