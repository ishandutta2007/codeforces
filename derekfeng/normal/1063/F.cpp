#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=10000007,H=37;
int n,m,a[500005];
char s[500005];
bitset<P>bs;
bitset<500005>ok,nok;
int pw[500005],hsh[500005],pre[500005];
int gethash(int l,int r){return (pre[r]-(ll)pre[l-1]*pw[r-l+1]%P+P)%P;}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'a';
	m=floor(sqrt(2*n))+1;
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=(ll)pw[i-1]*H%P,pre[i]=((ll)pre[i-1]*H+a[i])%P;
	for(int i=1;i<=n;i++)ok[i]=1;
	for(int i=2;i<=m;i++){
		for(int j=1;j+i-2<=n;j++)hsh[j]=gethash(j,j+i-2);
		nok.reset();
		bool ans=0;
		for(int j=n-i+1;j;j--){
			if(j+i<=n&&ok[j+i])bs[hsh[j+i]]=1;
			if(bs[hsh[j]]||bs[hsh[j+1]])nok[j]=1,ans=1;
		}
		bs.reset();
		swap(ok,nok);
		if(!ans){
			printf("%d",i-1);
			return 0;
		}
	}
}