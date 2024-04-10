#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 200;
int k;
int a[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	int now =0;
	int day =0;
	for (int i=0;i<n;i++){
		now+=a[i];
		day++;
		if (now>=8){
			now-=8;
			k-=8;
		}else{
			k-=now;
			now=0;
		}
		if (k<=0){
			cout<<day<<endl;
			return 00;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}