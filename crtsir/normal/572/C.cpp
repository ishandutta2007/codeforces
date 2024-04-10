#include<bits/stdc++.h>
using namespace std;
long long a,b,c,l,ans;
void did(long long lastlen){
	ans=ans-(lastlen+2)*(lastlen+1)/2;
}
int main(){
	cin>>a>>b>>c>>l;
	ans=(l+3)*(l+2)*(l+1)/6;
	for(long long i=0;i<=l;i++){
		if(a+i>=b+c)did(min(i,i-(a+b+c+i+1)/2+a)); 
		if(b+i>=a+c)did(min(i,i-(a+b+c+i+1)/2+b));
		if(c+i>=a+b)did(min(i,i-(a+b+c+i+1)/2+c));
	}
	cout<<ans;
}