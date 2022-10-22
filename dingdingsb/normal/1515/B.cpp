#include<bits/stdc++.h>
using namespace std;
bool issq(int x){
	int sq=(int)(sqrt(x)+0.5);
	return sq*sq==x;
}
signed main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n%2==0&&issq(n/2))puts("YES");
		else if(n%4==0&&issq(n/4))puts("YES");
		else puts("NO");
	}
}