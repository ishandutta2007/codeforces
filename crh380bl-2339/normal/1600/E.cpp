#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int n;
int a[200002];
int b[200002],c[200002],n1=0,n2=0;
int main(){
	int i,j;
	read(n);
	for(i=1;i<=n;++i)read(a[i]);
	a[0]=a[n+1]=-1;
	for(i=1;i<=n&&a[i]>a[i-1];++i)b[++n1]=a[i];
	for(i=n;i>=1&&a[i]>a[i+1];--i)c[++n2]=a[i];
	int s1=n1,s2=n2;
	bool flg=1;
	if(n1+n2>n){
		if(n1==1||n2==1){
			puts("Alice");
			return 0;
		}
		else{
			n1-=2;
			n2-=2;
		}
	}
	if(n1==0&&n2==0){
		puts("Bob");
		return 0;
	}
	for(i=j=1;i<=n1||j<=n2;){
		if(i>n1){
			if(s2&1);
			else flg^=1;
			break;
		}
		if(j>n2){
			if(s1&1);
			else flg^=1;
			break;
		}
		if(b[i]==c[j]){
			if((s1&1)||(s2&1));
			else flg^=1;
			break;
		}
		if(b[i]>c[j]){
			if(s1&1)break;
			else{
				++j;
				--s2;
				flg^=1;
			}
		}
		else{
			if(s2&1)break;
			else{
				++i;
				--s1;
				flg^=1;
			}
		}
	}
	if(flg)puts("Alice");
	else puts("Bob");
	return 0;
}