#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s;
int n,i,r,g,b;

int main()
{
	scanf("%d",&n);
	cin>>s;
	
	for(i=0;i<n;i++){
		b+=(s[i]=='B');
		g+=(s[i]=='G');
		r+=(s[i]=='R');
	}
	
	if(b==0){
		if(g>0 && r>0) printf("B");
	}else{
		if(g>0 && r>0) printf("B");
		else if(g>1 || r>1) printf("B");
		else if(g==0 && r==0) printf("B");
	}
	
	if(g==0){
		if(r>0 && b>0) printf("G");
	}else{
		if(r>0 && b>0) printf("G");
		else if(r>1 || b>1) printf("G");
		else if(r==0 && b==0) printf("G");
	}
	
	if(r==0){
		if(b>0 && g>0) printf("R");
	}else{
		if(b>0 && g>0) printf("R");
		else if(b>1 || g>1) printf("R");
		else if(b==0 && g==0) printf("R");
	}
	
	
	
	return 0;
}