#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
char s[MAX_N];
typedef long long ll;
int a[MAX_N],b[MAX_N];
int main(){
	int l,n; scanf("%d",&l),n=l;
	scanf("%s",s+1);
	int d=l/2+1; while(s[d+1]=='0'&&d<=n) ++d;
	for(int i=1;i<=n;++i)
		if(i>d) a[n-i+1]+=s[i]-'0';
		else a[d-i+1]+=s[i]-'0';
	d=l/2; while(s[d+1]=='0') --d; 
	for(int i=1;i<=n;++i)
		if(i>d) b[n-i+1]+=s[i]-'0';
		else b[d-i+1]+=s[i]-'0';
	for(int i=1;i<=n+2;++i){
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	for(int i=1;i<=n+2;++i){
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	for(int i=n+2;i>=1;--i){
		if(a[i]>b[i]){
			for(int j=1;j<=n+1;++j)
				a[j]=b[j];
			break;
		}else if(a[i]<b[i]) break;
	}
	int j=n+1;
	while(a[j]==0) --j;
	for(;j;--j) printf("%d",a[j]);
	return 0;
}