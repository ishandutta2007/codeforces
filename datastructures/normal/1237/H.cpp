#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n;
char a[4005],b[4005];
int ans[4005],tot;
void swp(int x){
	ans[++tot]=x;
	for (int i=1,j=x;i<j;i++,j--)swap(a[i],a[j]);
	return;
}
int main(){
	cin>>t;
	while(t--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		n=strlen(a+1);
		tot=0;
		int fg=1;
		for (int i=n-1;i>=1&&fg==1;i-=2){
			if (b[i]=='0'&&b[i+1]=='0'){
				if (a[i]=='0'&&a[i+1]=='0')continue;
				int k=1;
				while(k<=i&&(a[k]!='0'||a[k+1]!='0'))k+=2;
				if (k>i){
					fg=0;
					break;
				}
				if (k!=1)swp(k+1);
				swp(i+1);
			}
			if (b[i]=='1'&&b[i+1]=='1'){
				if (a[i]=='1'&&a[i+1]=='1')continue;
				int k=1;
				while(k<=i&&(a[k]!='1'||a[k+1]!='1'))k+=2;
				if (k>i){
					fg=0;
					break;
				}
				if (k!=1)swp(k+1);
				swp(i+1);
			}
			if (b[i]=='1'&&b[i+1]=='0'){
				if (a[i]=='1'&&a[i+1]=='0')continue;
				if (a[1]=='0'&&a[2]=='1'){
					swp(i+1);
					continue;
				}
				int k=1;
				while(k<=i&&(a[k]!='1'||a[k+1]!='0'))k+=2;
				if (k<=i){
					swp(k+1);
					swp(i+1);
					continue;
				}
				k=1;
				while(k<=i&&(a[k]!='0'||a[k+1]!='1'))k+=2;
				if (k>i){
					fg=0;
					break;
				}
				swp(k+1);
				swp(2);
				swp(i+1);
			}
			if (b[i]=='0'&&b[i+1]=='1'){
				if (a[i]=='0'&&a[i+1]=='1')continue;
				if (a[1]=='1'&&a[2]=='0'){
					swp(i+1);
					continue;
				}
				int k=1;
				while(k<=i&&(a[k]!='0'||a[k+1]!='1'))k+=2;
				if (k<=i){
					swp(k+1);
					swp(i+1);
					continue;
				}
				k=1;
				while(k<=i&&(a[k]!='1'||a[k+1]!='0'))k+=2;
				if (k>i){
					fg=0;
					break;
				}
				swp(k+1);
				swp(2);
				swp(i+1);
			}
		}
		if (fg==0)cout<<-1<<endl;
		else{
			cout<<tot<<endl;
			for (int i=1;i<=tot;i++)cout<<ans[i]<<' ';
			cout<<endl;
		}
	}
	return 0;
}