#include <bits/stdc++.h>
using namespace std;
int t,a,b,c,d,x,y,X,Y,XX,YY;
void MAIN(){
	if (a|b && X==XX){
		puts("No");
	}else if (c|d && Y==YY){
		puts("No");
	}else if (b-a+x<X || b-a+x>XX){
		puts("No");
	}else if (d-c+y<Y || d-c+y>YY){
		puts("No");
	}else puts("Yes");
}
int main(){
	cin>>t;
	while (t--){
		cin>>a>>b>>c>>d>>x>>y>>X>>Y>>XX>>YY;
		MAIN();
	}
}