#include<bits/stdc++.h>
using namespace std;
int n,num=0;
void solve(){
	cin>>n;
	if(n%2==0){
		for(int i=0;i<n/2;i++)putchar('a');
		putchar('b');
		for(int i=1;i<n/2;i++)putchar('a');
		return;
	}else{
		if(n<=26){
			for(int i=0;i<n;i++)putchar('a'+i);
			return;
		}
		int num=(n-1)/2;
		for(int i=0;i<num;i++)putchar('a');
		putchar('b');
		for(int i=1;i<num;i++)putchar('a');
		putchar('c');
	}
}
int main(){
	int Tc;
	for(cin>>Tc;Tc--;)solve(),puts("");
}