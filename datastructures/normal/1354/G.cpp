#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int t,n,k;
int cmp(int l1,int r1,int l2,int r2){
	cout<<'?'<<' '<<r1-l1+1<<' '<<r2-l2+1<<endl;
	for (int i=l1;i<=r1;i++)cout<<i<<' ';cout<<endl;
	for (int i=l2;i<=r2;i++)cout<<i<<' ';cout<<endl;
	string s;
	cin>>s;
	if (s[0]=='F')return 1;
	if (s[0]=='S')return 2;
	return 0;
}
bool check1(){
	for (int i=1;i<=25;i++){
		int x=rand()%n+1;
		while(x==1)x=rand()%n+1;
		if (cmp(1,1,x,x)==2)return 1;
	}
	return 0;
}
bool check(int l,int r){
	return cmp(1,r-l+1,l,r)==1;
}
int work(int l,int r){
	if (l==r)return l;
	int mid=(l+r)/2;
	if (check(l,mid))return work(l,mid);
	return work(mid+1,r);
}
int main(){
	srand(time(NULL));
	cin>>t;
	while(t--){
		cin>>n>>k;
		if (check1()){
			puts("! 1");
			continue;
		}
		int nowl=2,nowr=2;
		while(check(nowl,nowr)==0){
			int nxtl=min(nowr+1,n),nxtr=min(nowr*2,n);
			nowl=nxtl,nowr=nxtr;
		}
		int ans=work(nowl,nowr);
		cout<<'!'<<' '<<ans<<endl;
	}
	return 0;
}