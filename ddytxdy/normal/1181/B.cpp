#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],b[N],ans[N],anss[N];char c[N];
void change(int s,int t,int *a){
	a[0]=t-s+1;
	for(int i=1;i<=a[0];i++)a[i]=c[s+a[0]-i]-'0';
}
void jia(int a[],int b[],int c[]){
	c[0]=max(a[0],b[0])+2;
	int x=0;
	for(int i=1;i<=c[0];i++){
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;c[i]%=10;
	}
	while(c[0]&&!c[c[0]])c[0]--;
}
bool cmp(int a[],int b[]){
	if(a[0]!=b[0])return a[0]>b[0];
	for(int i=a[0];i;i--){
		if(a[i]!=b[i])return a[i]>b[i];
	}
	return 0;
}
void print(int a[]){
	if(!a[0])putchar('0');
	for(int i=a[0];i;i--)printf("%d",a[i]);
	puts("");
}
void solve(int x){
	if(x<=0||x>n||c[x]=='0')return;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	change(1,x-1,a);change(x,n,b);//print(a);print(b);
	jia(a,b,anss);
	if(cmp(ans,anss))memcpy(ans,anss,sizeof(ans));
}
int main(){
	scanf("%d%s",&n,c+1);
	int mid=n/2,d=0;
	for(;;d++){
		if(mid-d>0&&c[mid-d]!='0')break;
		if(mid+d<=n&&c[mid+d]!='0')break;
	}
		
	ans[0]=1e9;
	for(int i=d;i<d+3;i++)solve(mid-i),solve(mid+i);
	print(ans);
	return 0;
}