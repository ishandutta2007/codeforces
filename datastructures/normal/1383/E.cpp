#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;
int n,f[1000005],sum;
char s[1000005];
int tag,val[1000005];
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int cnt=0,p=1;
	f[0]=1;
	while(p<=n&&s[p]=='0')f[p]=1,p++;
	if (p>n){
		cout<<n<<endl;
		return 0;
	}
	for (int i=p;i<=n;i++){
		if (s[i]=='1'){
			int j=i;
			while(j>=1&&(j==i||s[j]=='0')){
				j--;
				upd(f[i],f[j]);
			}
			cnt=0;
			upd(tag,f[i]);
		}
		else{
			cnt++;
			upd(f[i],val[cnt]);
			upd(f[i],tag);
			val[cnt]=mod-tag;
		}
	}
	for (int i=1;i<=n;i++)
		if (s[i]=='1')upd(sum,f[i]);
	p=n;
	while(p>=1&&s[p]=='0')p--;
	cout<<(1ll*sum*(n-p+1)%mod+mod)%mod<<endl;
	return 0;
}