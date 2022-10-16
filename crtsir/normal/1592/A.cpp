#include<bits/stdc++.h>
using namespace std;
int T,n,h,a[100003]; 
bool cmp(int x,int y){return x>y;}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>h;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n,cmp);
		cout<<h/(a[0]+a[1])*2+(h%(a[0]+a[1])>a[0]?2:(h%(a[0]+a[1])?1:0))<<endl;;
	}
}