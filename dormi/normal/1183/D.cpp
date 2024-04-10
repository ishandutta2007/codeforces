#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	int n;
    	cin>>n;
	    int am[n];
	    memset(am,0,sizeof(am));
	    int in;
	    for(int i=0;i<n;i++){
	    	cin>>in;
	    	am[(in-1)]++;
	    }
	    sort(am,am+n);
	    int cnd=0;
	    int lastput=INT_MAX;
	    for(int i=n-1;i>=0;i--){
	    	int te=max(0,min(am[i],lastput-1));
	    	lastput=te;
	    	cnd+=te;
	    }
	    printf("%d\n",cnd);
    }
    return 0;
}