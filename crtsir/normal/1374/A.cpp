#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		int x,y,n;cin>>x>>y>>n;
		n-=y;cout<<(n/x)*x+y<<endl;
	}
}