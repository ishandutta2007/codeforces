#include<bits/stdc++.h>
using namespace std;
int T;
int main(){cin>>T;
	while(T--){
		int a,b,c;cin>>a>>b>>c;
		if(a>=c)cout<<-1;else cout<<1;cout<<' ';
		if(a<=c*1.0/b)cout<<-1;else cout<<b;cout<<endl;
	}
}