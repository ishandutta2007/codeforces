//  228

#include<bits/stdc++.h>
using namespace std;

int a[5];
int b[4],c[5];
int keyi;

void dfs(int now){
	if(now==4) {
		if(b[1]+b[2]>b[3]&&b[1]+b[3]>b[2]&&b[2]+b[3]>b[1]) {cout<<"TRIANGLE"<<endl; exit(0);}
		if(b[1]+b[2]>=b[3]&&b[1]+b[3]>=b[2]&&b[2]+b[3]>=b[1]) {keyi=2;return;}
		return;
	}
	for(int i=1;i<=4;i++){
		if(c[i]==0){
			c[i]=1;
			b[now]=a[i];
			now++;
			dfs(now);
			now--;
			b[now]=0;
			c[i]=0;
		}
	}
}

int main()
{
	for(int i=1;i<=4;i++)
		cin>>a[i];
	dfs(1);
	if(keyi==2) cout<<"SEGMENT"<<endl;
	if(keyi==0) cout<<"IMPOSSIBLE"<<endl;
	return 0;
}