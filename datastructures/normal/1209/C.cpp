#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n;
string x;
int a[200005],book[200005];
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book)); 
		cin>>n;
		cin>>x;
		for (int i=0;i<x.size();i++)a[i+1]=x[i]-'0';
		int flag=0;
		for (int i=0;i<=9&&flag==0;i++){
			memset(book,0,sizeof(book));
			int now=0,f=1;
			for (int j=1;j<=n&&f;j++){
				if (a[j]>=i)continue;
				if (a[j]<now)f=0;
				now=a[j],book[j]=1;
			}
			if (f==0)break;
			for (int j=n;j>=1;j--){
				if (book[j])break;
				if (a[j]==i)book[j]=1;
			}
			now=i;
			for (int j=1;j<=n&&f;j++){
				if (book[j])continue;
				if (a[j]<now)f=0;
				now=a[j];
			}
			if (f==0)continue;
			flag=1;
			for (int j=1;j<=n;j++)printf("%d",2-book[j]);
			cout<<endl;
		}
		if (flag==0)cout<<'-'<<endl;
	}
	return 0;
}