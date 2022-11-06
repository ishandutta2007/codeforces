#include<bits/stdc++.h>
#define N 1000005
#define INF 1000000000
using namespace std;
int main(){
	int n,k;
	int t;
	cin>>n>>k;
	for(int i=0;i<n;++i){
		t=i%k;
		printf("%c",t+'a');
	}
	puts("");
	return 0;
}