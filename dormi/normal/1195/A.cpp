#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int am[k+1]={ };
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		am[in]+=1;
	}
	int oddcnt=0;
	for(int i=1;i<=k;i++){
		if(am[i]%2){
			oddcnt+=1;
		}
	}
	printf("%d\n",n-oddcnt/2);
	return 0;
}