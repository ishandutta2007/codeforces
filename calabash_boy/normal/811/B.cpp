#include<bits/stdc++.h>
using namespace std;
#define MAXN 10004
int a[MAXN];
int b[MAXN];
int m,n;
bool cmp(int a1,int a2){
	return a1<a2;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	for (int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		int count=0;
		for (int j=l;j<=r;j++){
			if (b[j]<b[x]){
				count++;
			}
		}
		if (count==x-l){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}