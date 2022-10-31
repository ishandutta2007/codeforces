#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int t,n,x,y; 

int main(){
//	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)putchar('(');
			for(int j=1;j<=i;j++)putchar(')');
			for(int j=i+1;j<=n;j++)putchar('('),putchar(')');putchar('\n');
		}
		
	}
}