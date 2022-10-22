#include<bits/stdc++.h>
using namespace std;
int T,n,t1,t2,w,b;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>t1>>t2;
		cin>>w>>b;
		puts(((t1+t2)>=w*2&&(n*2-t1-t2)>=b*2)?"YES":"NO");
	}
}