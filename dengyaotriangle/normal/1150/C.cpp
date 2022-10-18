#include<bits/stdc++.h>

using namespace std;

const int maxn=400005;

int n;
int c1,c2;
bool icp[403004];
int prm[403000],pc;
void seive(int n){
	for(int i=2;i<n;i++){
		if(!icp[i])prm[++pc]=i;
		if(i>sqrt(n))continue;
		for(int j=i*i;j<n;j+=i){
			icp[j]=1;
		}
	}

}
void ot(){
	if(c2){
		cout<<"2 ";
		c2--;
	}else{
		cout<<"1 1 ";
		c1-=2;
	}
}
int main(){
	seive(403000);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;scanf("%d",&t);
		if(t==1) c1++;
		else c2++;
	}
	if(n==1){
		cout<<(c1?1:2);
		return 0;
	}
	ot();
	if(c1==0){
		while(c2--){
			cout<<"2 ";
		}
		return 0;
	}
	cout<<"1 ";
	c1--;
	while(c2--){
		cout<<"2 ";
	}
	while(c1--){
		cout<<"1 ";
	}
	return 0;
}