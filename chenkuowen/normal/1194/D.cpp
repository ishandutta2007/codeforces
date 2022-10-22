#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,k,cnt=0; scanf("%d%d",&n,&k);
		if(k%3==0){
			int key=n%(k+1);
			if(key%3!=0||key>=k-1) puts("Alice");
			else puts("Bob");
		}else{
			if(n%3) puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
}