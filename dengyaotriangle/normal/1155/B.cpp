#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
char x[maxn];

int main(){
	cin>>n>>(x+1);
	int cnt=0;
	for(int i=1;i<=n-10;i++){
		if(x[i]=='8') cnt++;
	}
	int tm=(n-11)/2;
	
	if(cnt>tm){
		cout<<"YES";
	}else cout<<"NO";
	return 0;
}