#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	int n,k;
    	cin>>n>>k;
    	int lo=0;
    	int hi=200000000;
    	int in;
    	for(int i=0;i<n;i++){
			cin>>in;
			lo=max(lo,in-k);
			hi=min(hi,in+k);
    	}
    	if(hi>=lo){
    		printf("%d\n",hi);
    	}
    	else{
    		printf("-1\n");
    	}
    }
    return 0;
}