#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    if(n%2==0){
    	if(n==2)printf("1\n");
    	else printf("2\n");
    	return 0;
    }
    bool prime=true;
    for(lli i=2;i<=sqrt(n)&&prime;i++){
    	if(n%i==0)prime=false;
    }
    if(prime){
    	printf("1\n");
    	return 0;
    }
    n-=2;
	prime=true;
	for(lli i=2;i<=sqrt(n)&&prime;i++){
		if(n%i==0)prime=false;
	}
	if(prime){
		printf("2\n");
		return 0;
	}
	printf("3\n");
    return 0;
}