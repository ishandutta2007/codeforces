#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int T,n;
char c[100004];
int N,num,fac[300004],inv[300004];
int C(int a,int b){
	if(a<b)return 0;
	return (ll)fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
void init(){
	fac[0]=1;
	int m=3e5;
	for(int i=1;i<=m;i++)fac[i]=(ll)fac[i-1]*i%MOD;
	inv[1]=1;
	for(int i=2;i<=m;i++)inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	inv[0]=1;
	for(int i=1;i<=m;i++)inv[i]=(ll)inv[i]*inv[i-1]%MOD;
}
void sol(){
	num=0;
	int all=0;
	cin>>n;scanf("%s",c);
	for(int i=0;i<n;){
		if(c[i]=='0')i++;
		else{
			int cnt=0,j;
			for(j=i;j<n&&c[j]=='1';j++,cnt++,all++);
			if(cnt&1)num++;
			i=j;
		}
	}
	int cur=(all-num)/2;
	printf("%d\n",C(n-all+cur,cur));
}
int main(){
	init();
	cin>>T;
	while(T--)sol();
}