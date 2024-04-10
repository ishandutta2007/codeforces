#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int offset=1<<7;
    printf("?");
	for(int i=0;i<100;i++){
		printf(" %d",i);
	}
	printf("\n");
	int a;
	cin>>a;
	assert(a!=-1);
	int ans=0;
	for(int i=7;i<14;i++){
		if(a&(1<<i)){
			ans+=(1<<i);
		}
	}
	printf("?");
	for(int i=1;i<=100;i++){
		printf(" %d",i*offset);
	}
	printf("\n");
	cin>>a;
	assert(a!=-1);
	for(int i=0;i<7;i++){
		if(a&(1<<i)){
			ans+=(1<<i);
		}
	}
	printf("! %d\n",ans);
    return 0;
}