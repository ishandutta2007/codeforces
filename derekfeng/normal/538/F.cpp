#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;int ret=1;
	for(;ch==' '||ch=='\n';ch=getchar());
	if(ch=='-')ret=-1,ch=getchar();
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
	x*=ret;
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0'); 
}
int n,a[200004],ans[200004];
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=2;i<=n;i++){
		int l=1;
		while(l<n){
			int num=(i-2)/l;
			if(num==0){
				if(a[1]>a[i])ans[l]++;
				break;
			}
			int r=(i-2)/num;
			if(a[num+1]>a[i])ans[l]++,ans[r+1]--;
			l=r+1;
		}
	}
	for(int i=1;i<n;i++)ans[i]+=ans[i-1],write(ans[i]),putchar(' ');
}