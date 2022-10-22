#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
typedef long long ll;
map<ll,int>mp;
int a[100004],num[55],nump[55];
void MAIN(){
	ll n,numdd=0;cin>>n;int m;read(m);
	for (int i=1;i<=m;i++){
		read(a[i]),numdd+=a[i];
	}
	if (numdd<n){
		puts("-1");return;
	}
	int ans=0;
	for (int i=0;i<55;i++) num[i]=0;
	for (int i=1;i<=m;i++) num[mp[a[i]]]++;
	for (int i=0;i<55;i++){
		if ((1ll<<i)&n){
			if (num[i]==0){
				int j=i+1;
				while (j<55 && num[j]==0) j++;
				if (j==55){
					puts("-1");return;
				}
				num[j]--;
				ans+=j-i;
				for (int k=j-1;k>i;k--) num[k]++;
				num[i]+=2;
			}
			num[i]--;
		}
		if (i!=54) num[i+1]+=num[i]/2;
	}
	cout<<ans<<"\n";
}
int main(){
	for (int i=0;i<55;i++) mp[1ll<<i]=i;
	int T;cin>>T;
	while (T--) MAIN();
}