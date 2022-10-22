#include<bits/stdc++.h>
using namespace std;
int T,n,K;
void sol(){
	vector<int>a,b;
	scanf("%d%d",&n,&K);
	if(K<n-1){
		a.push_back(n-1),b.push_back(K);
		for(int i=1;i<n/2;i++)
			if(i!=K&&i!=n-1-K)a.push_back(i),b.push_back(n-1-i);
		a.push_back(0),b.push_back(n-1-K);
		for(int i=0;i<n/2;i++)printf("%d %d\n",a[i],b[i]);
	}else if(n>4){
		a.push_back(n-1),b.push_back(n-2);
		a.push_back(1),b.push_back(3);
		for(int i=4;i<n/2;i++)a.push_back(i),b.push_back(n-1-i);
		a.push_back(n-3),b.push_back(0);
		a.push_back(n-4),b.push_back(2);
		for(int i=0;i<n/2;i++)printf("%d %d\n",a[i],b[i]);
	}else puts("-1");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}