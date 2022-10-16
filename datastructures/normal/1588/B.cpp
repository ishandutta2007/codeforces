#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <random>
#include <ctime>
#define int long long
using namespace std;
mt19937 rnd(time(NULL));
int read(){
	int x=0,fg=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if (ch=='-')fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*fg;
}
int t,n;
int ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	return x;
}
bool check(int x){
	int awa=ask(1,x);
	if (awa==0)return 0;
	return 1;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int l=1,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		int pos1=ans-1;
		int len1=ask(pos1,n)-ask(pos1+1,n)+1;
		int pos2=pos1+len1;
		int len2=ask(pos2,n)-ask(pos2+1,n)+1;
		int pos3=pos2+len2-1;
		cout<<"! "<<pos1<<' '<<pos2<<' '<<pos3<<endl;
		fflush(stdout);
	}
	return 0;
}