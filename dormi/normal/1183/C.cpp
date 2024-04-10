#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
bool check(lli k, lli n, lli a, lli b, lli amb){
	k-=amb*b;
	if(k+b>b){
		if((n-amb)*a<k){
			return 1;
		}
		return 0;
	}
	else{
		return 0;
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	lli k,n,a,b;
    	cin>>k>>n>>a>>b;
    	lli lo=0;
    	lli hi=n;
    	while(lo!=hi){
    		lli mid=(lo+hi)/2;
			if(check(k,n,a,b,mid)){
				hi=mid;
			}
			else{
				lo=mid+1;
			}
    	}
		if(check(k,n,a,b,lo)){
			printf("%lli\n",n-lo);
		}
		else{
			printf("-1\n");
		}
    }
    return 0;
}