#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define int long long
using namespace std;
int n,m,s[5005],f[5005],h[5005];
int l[5005],r[5005];
int a[5005],b[5005],c[5005];
int num,cnt;
void upd(int col,int pos){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	int nownum=1,nowcnt=1;
	if (col==0&&pos==0)nownum=0;
	for (int i=1;i<=m;i++){
		if (f[i]!=col){
			if (l[i]>=pos&&r[i]>pos)a[f[i]]++;
			if (l[i]<pos&&r[i]<=pos)b[f[i]]++;
			if (l[i]<pos&&r[i]>pos)c[f[i]]++;
		}
		else if (r[i]>pos)b[f[i]]++;
	}
	for (int i=1;i<=m;i++)
		if (f[i]==col&&l[i]==pos&&r[i]>pos){
			b[f[i]]--;
			break;
		}
	for (int i=1;i<=n;i++){
		if (a[i]==0&&b[i]==0&&c[i]==0)continue;
		if ((a[i]>0&&b[i]>0)||(a[i]>0&&c[i]>0)||(b[i]>0&&c[i]>0)||(c[i]>=2)){
			int nows=0;
			nows=(nows+a[i]*(b[i]+c[i]))%mod;
			nows=(nows+c[i]*(b[i]+c[i]-1))%mod;
			nownum+=2;
			nowcnt=nowcnt*nows%mod;
		}
		else{
			int nows=(a[i]+b[i]+2*c[i])%mod;
			nownum++;
			nowcnt=nowcnt*nows%mod;
		}
	}
	if (nownum==num)cnt=(cnt+nowcnt)%mod;
	else if (nownum>num)num=nownum,cnt=nowcnt;
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)cin>>s[i];
	for (int i=1;i<=m;i++)cin>>f[i]>>h[i];
	for (int i=1;i<=m;i++){
		int cnt;
		cnt=0,l[i]=n+1;
		for (int j=1;j<=n;j++){
			if (s[j]==f[i])cnt++;
			if (cnt==h[i]){
				l[i]=j;
				break;
			}
		}
		cnt=0,r[i]=0;
		for (int j=n;j>=1;j--){
			if (s[j]==f[i])cnt++;
			if (cnt==h[i]){
				r[i]=j;
				break;
			}
		}
	}
	upd(0,0); 
	for (int i=1;i<=m;i++)
		if (l[i]<=n)upd(f[i],l[i]);
	cout<<num<<' '<<cnt<<endl;
	return 0;
}