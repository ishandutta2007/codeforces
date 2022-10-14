#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n;
    cin>>n;
    lli a=1;
    lli b=2;
    lli num=1;
    while(true) {
	    if (n < b) {
		    printf("%lli\n", num-1);
		    return 0;
	    }
	    num+=1;
	    lli te=b;
	    b+=a;
	    a=te;
    }
    return 0;
}