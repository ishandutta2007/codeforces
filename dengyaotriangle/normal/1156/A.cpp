#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n;
int a[maxn];

int main(){
	int ans=0;
	cin>>n;
	bool fin=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)continue;
		if(a[i]==a[i-1])fin=0;
		if(a[i]==2&&a[i-1]==3) fin=0;
		if(a[i-1]==2&&a[i]==3) fin=0;
		if(a[i-1]==1){
			if(a[i]==2)cnt+=3;
			if(a[i]==3)cnt+=4;
		}else if(a[i-1]==2){
			if(a[i]==1)cnt+=3;
		}else if(a[i-1]==3){
			if(a[i]==1)cnt+=4;
		}
		if(a[i]==2&&a[i-1]==1){
			if(i>2){
				if(a[i-2]==3) cnt--;
			}
		}
	}
	if(fin){
		cout<<"Finite"<<endl<<cnt;
	}else{
		cout<<"Infinite";
	}
	return 0;
}