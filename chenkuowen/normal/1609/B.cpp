#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
char s[N];
int n,cnt=0;
bool check(int x){
	if(x<1||x+2>n) return 0;
	return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';
}
int main(){
	int m; scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) cnt+=check(i);
//	printf("<%d>\n",cnt);
	while(m--){
		int pos; char ch[5];
		scanf("%d%s",&pos,ch);
		for(int i=pos-3;i<=pos+3;++i)
			cnt-=check(i);
		s[pos]=ch[0];
		for(int i=pos-3;i<=pos+3;++i)
			cnt+=check(i);
		printf("%d\n",cnt);
	}
	return 0;
}