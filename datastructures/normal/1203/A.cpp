#include <iostream>
#include <cstdio>
using namespace std;
int a[205],n,q;
int main(){
//	freopen("1203A.in","r",stdin);
//	freopen("1203A.out","w",stdout);
	cin>>q;
	while(q--){
		cin>>n;
		int now,x,flag1=1,flag2=1;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]==1)x=i;
		}
		now=x;
		for (int i=1;i<=n;i++){
			if (a[now]!=i)flag1=0;
			now--;
			if (now==0)now=n;
		}
		now=x;
		for (int i=1;i<=n;i++){
			if (a[now]!=i)flag2=0;
			now++;
			if (now>n)now=1;
		}
		if (flag1||flag2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}