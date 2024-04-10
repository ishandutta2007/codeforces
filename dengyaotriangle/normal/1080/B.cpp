#include<bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
    	long long l,r;
    	cin>>l>>r;
    	long long k1=l/2,k2=(r+1)/2;;
    	if((l-1)%2) k1=0-k1;
    	if((r)%2) k2=0-k2;
    	cout<<k2-k1<<endl;
	}
	// 0  1 2  3 4  5 6
	// 0 -1 2 -3 4 -5 6
	// 0 -1 1 -2 2 -3 3
    return 0;
}