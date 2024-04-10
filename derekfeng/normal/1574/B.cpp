#include<bits/stdc++.h>
using namespace std;
int a[3],m,t;
int main(){
	cin>>t;
	while(t--){
		cin>>a[0]>>a[1]>>a[2]>>m;
		if((a[0]-1)+(a[1]-1)+(a[2]-1)<m)puts("NO");
		else{
			int f=max(a[0],max(a[1],a[2]));
			if(f-m-1<=a[0]+a[1]+a[2]-f)puts("YES");
			else puts("NO");
		}
	}
}