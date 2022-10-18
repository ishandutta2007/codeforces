#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
long long x,y;

int main(){
    cin>>n;
    while(n--){
    	cin>>x>>y;
    	if(x+y>ans) ans=x+y;
	}
	cout<<ans;
    return 0; 
}