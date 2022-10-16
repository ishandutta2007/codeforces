#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		cout<<max(0,c-a-2-a-2+c)<<endl;
	}
}