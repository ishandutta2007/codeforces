#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	string a,b;
    	cin>>a>>b;
    	int loc2=-1;
	    for(int i=0;i<b.size();i++){
		    if(b[i]=='1')loc2=(int)b.size()-i-1;
	    }
    	for(int i=(int)a.size()-loc2-1;i>=0;i--){
    		if(a[i]=='1'){
    			printf("%d\n",(int)a.size()-loc2-1-i);
    			break;
    		}
    	}

    }
    return 0;
}