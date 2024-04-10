#include <iostream>
#include <cstdio>
using namespace std;
int n,l;
string x;
int a[1000005],b[1000005];
int main(){
//	freopen("c.in","r",stdin);
//	freopen("c.out","w",stdout);
	cin>>l>>x;
	n=x.size();
	int f=1;
	for (int i=1;i<=n;i++)a[i]=x[i-1]-'0';
	for (int i=1;i<=n;i++)
		if (a[i]!=9)f=0;
	if (n%l==0&&f==0){
		for (int i=1;i<=n/l;i++)
			for (int j=1;j<=l;j++)
				b[(i-1)*l+j]=a[j];
		int flag=0;
		for (int i=1;i<=n;i++){
			if (b[i]>a[i])flag=1;
			if (a[i]>b[i])break;
		}
		if (flag==1){
			for (int i=1;i<=n;i++)printf("%d",b[i]);
			cout<<endl;
		}
		if (flag==0){
			for (int i=n;i>=1;i--){
				if (i%l==0)b[i]++;
				if (b[i]>=10)b[i]-=10,b[i-1]++;
			}
			for (int i=1;i<=n;i++)printf("%d",b[i]);
			cout<<endl;
		}
	}
	if (n%l!=0||f==1){
		for (int i=1;i<=n/l+1;i++){
			printf("1");
			for (int j=1;j<l;j++)printf("0");
		}
		cout<<endl;
	}
	return 0; 
}