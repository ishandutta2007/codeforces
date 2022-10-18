#include<bits/stdc++.h>

using namespace std;

const int maxn=205;

char x[maxn];
int v,mv;

int main(){
	int n;
	cin>>n;
	getchar();
	cin.getline(x,maxn);
	for(int i=0;i<n;i++){
		if(x[i]>='A'&&x[i]<='Z') v++;
		mv=max(v,mv);
		if(x[i]==' ') v=0;
	}
	cout<<mv;
	return 0;
}