#include<bits/stdc++.h>
using namespace std;
int t,x;
int main(){
	cin>>t;
	while(t--){
		cin>>x;
		if(x%11==0||x-x%11>=x%11*110)puts("YES");
		else puts("NO");
	}
}