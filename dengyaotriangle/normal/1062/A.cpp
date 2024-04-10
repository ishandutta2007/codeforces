#include<bits/stdc++.h>
using namespace std;

const int maxn=105;

int a[maxn];
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=0;
	a[n+1]=1001;
	int cl=1;
	int ml=1;
	for(int i=1;i<=n+1;i++){
		if(a[i]-1==a[i-1]){
			cl++;
			ml=max(ml,cl);
		}else cl=1;
	}
	cout<<max(0,ml-2);
	return 0;
}