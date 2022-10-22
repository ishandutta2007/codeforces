#include<cstdio>
using namespace std;
const int o=1e5+10;
int n,q,ans;char s[o],t[2];
inline int calc(int pos){if(pos<1||pos>n-2) return 0;return s[pos]=='a'&&s[pos+1]=='b'&&s[pos+2]=='c';}
int main(){
	scanf("%d%d%s",&n,&q,s+1);
	for(int i=1;i<=n;++i) ans+=calc(i);
	for(int pos;q--;printf("%d\n",ans)) scanf("%d%s",&pos,t),ans-=calc(pos-2)+calc(pos-1)+calc(pos),s[pos]=t[0],ans+=calc(pos-2)+calc(pos-1)+calc(pos);
	return 0;
}