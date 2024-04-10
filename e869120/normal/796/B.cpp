#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,a,b;bool used[1000500];
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){scanf("%d",&a);used[a]=true;}
	int cx=1;
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		if(used[cx]==false){
			if(cx==a)cx=b;else if(cx==b)cx=a;
		}
	}
	cout<<cx<<endl;
	return 0;
}