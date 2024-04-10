#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int n,a[o],b[o];char s[o];long long l,r;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	scanf("%s",s+1);
	sort(a+1,a+n+1);
	for(int i=n,l=1,r=n;i;--i)
		if(s[i]^s[i-1]) b[i]=a[r--];
		else b[i]=a[l++];
	for(int i=1;i<=n;++i)
		if(s[i]=='L')
			if(l>r+b[i]) printf("%d R\n",b[i]),r+=b[i];
			else printf("%d L\n",b[i]),l+=b[i];
		else
			if(r>l+b[i]) printf("%d L\n",b[i]),l+=b[i];
			else printf("%d R\n",b[i]),r+=b[i];
	return 0;
}