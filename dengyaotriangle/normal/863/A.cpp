#include<bits/stdc++.h>

using namespace std;

const int maxn =120;

char x[maxn];
int n;

int main(){
	cin>>x;
	while(x[n])n++;
	int l=n-1;
	while(x[l]=='0')l--;
	for(int i=0;i<=l;i++){
		if(x[i]!=x[l-i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}