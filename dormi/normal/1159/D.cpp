#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
// 	if(n%2){
// 		for(int i=0;i<(n-k)/2;i++){
// 			printf("0");
// 		}
// 		for(int i=0;i<k;i++){
// 			if(i%2) {
// 				printf("0");
// 			}
// 			else{
// 				printf("1");
// 			}
// 		}
// 		for(int i=0;i<(n-k)/2;i++){
// 			printf("0");
// 		}
// 	}
//	else{
		for(int i=0;i<ceil((n-k)/2);i++){
			printf("0");
		}
	//	int ones=0;
// 		if((n-k)/2%2){
// 			printf("0");
// 		}
		for(int i=0;i</*k-((n-k)/2%2)*/n-ceil((n-k)/2);i++){
// 			if(i==k-1&&ones==1){
// 				printf("1");
// 			}
		//	else {
				if (i%(int)ceil((n-k)/(double)2+(double)1)) {
					printf("0");
				} else {
				//	ones += 1;
					printf("1");
				}
		//	}
		}
// 		for(int i=0;i<(n-k)/2;i++){
// 			printf("0");
// 		}
//	}
}