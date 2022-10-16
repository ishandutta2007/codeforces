#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n,a,b,x[103],y[103];
	cin>>T;
	while(T--){
		cin>>n>>a>>b;
		for(int i=0;i<a;i++)cin>>x[i];
		for(int i=0;i<b;i++)cin>>y[i];
		sort(x,x+a);sort(y,y+b);
		if(x[a-1]>y[b-1])
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}