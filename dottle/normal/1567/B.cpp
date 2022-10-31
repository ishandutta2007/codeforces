#include<bits/stdc++.h>
const int N=1000500;
using namespace std;

int yh[N],t,x,y;

int main(){
	ios::sync_with_stdio(false);
	for(int i=1;i<N;i++)yh[i]=yh[i-1]^i;
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(y==yh[x-1])cout<<x<<endl;
		else if((y^yh[x-1])==x) cout<<x+2<<endl;
		else cout<<x+1<<endl;
	}
}