#include <bits/stdc++.h>
using namespace std;
const int M=710;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,q;
map<int,int>mp[710];
int cnt[710],a[500004];
int main(){
	read(n),read(q);
	for (int i=0;i<n;i++)read(a[i]),mp[i/M][a[i]]++;
	while (q--){
		int oper,x;
		read(oper);
		if (oper==2){
			read(x);
			int l=0;
			while (l<=n/M && mp[l].find(x-cnt[l])==mp[l].end()) l++;
			if (l==n/M+1){
				puts("-1");continue;
			}
			int r=n/M;
			while (mp[r].find(x-cnt[r])==mp[r].end()) r--;
			int ld,rd;
			for (int i=l*M;;i++)
				if (a[i]+cnt[l]==x){
					ld=i;
					break;
				}
			for (int i=min(n,r*M+M)-1;;i--)
				if (a[i]+cnt[r]==x){
					rd=i;
					break;
				}
			write(rd-ld),puts("");
			continue;
		}
		int l,r;read(l),read(r),read(x),l--,r--;
		if (l/M==r/M){
			for (int i=l;i<=r;i++){
				mp[l/M][a[i]]--;
				if (mp[l/M][a[i]]==0) mp[l/M].erase(mp[l/M].find(a[i]));	
				mp[l/M][min(1000000001,a[i]+x)]++;
				a[i]=min(1000000001,a[i]+x);
			}
			continue;
		}
		for (int i=l;i<l/M*M+M;i++){
			mp[l/M][a[i]]--;
			if (mp[l/M][a[i]]==0) mp[l/M].erase(mp[l/M].find(a[i])); 
			mp[l/M][min(1000000001,a[i]+x)]++;
			a[i]=min(1000000001,a[i]+x);
		}
		for (int i=l/M+1;i<r/M;i++) cnt[i]=min(cnt[i]+x,1000000000);
		for (int i=r/M*M;i<=r;i++){
			mp[r/M][a[i]]--;
			if (mp[r/M][a[i]]==0) mp[r/M].erase(mp[r/M].find(a[i])); 
			mp[r/M][min(1000000001,a[i]+x)]++;
			a[i]=min(1000000001,a[i]+x);
		}
	}
}