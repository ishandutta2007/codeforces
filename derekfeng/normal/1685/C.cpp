#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[200004];
void sol(){
	scanf("%d%s",&n,s+1);
	int cnt=0,posl=-1,posr=-1;
	for(int i=1;i<=n+n;i++){
		cnt+=s[i]=='('?1:-1;
		if(cnt<0){
			posl=posl<0?i:posl;
			posr=i;
		}
	}
	if(posl<0){puts("0");return;}
	pair<int,int>pl={-n-n,0},pr={-n-n,0};
	cnt=0;
	for(int i=0;i<=n+n;i++){
		cnt+=s[i]=='('?1:-1;
		if(i<posl)pl=max(pl,{cnt,i+1});
		if(i>posr)pr=max(pr,{cnt,i});
	}
	reverse(s+pl.second,s+pr.second+1);
	cnt=0;int ok=1;
	for(int i=1;i<=n+n;i++){
		cnt+=s[i]=='('?1:-1;
		if(cnt<0)ok=0;
	}
	if(ok){
		puts("1");
		printf("%d %d\n",pl.second,pr.second);
		return;
	}
	reverse(s+pl.second,s+pr.second+1);
	pair<int,int>pos={-n-n,0};
	for(int i=1;i<=n+n;i++){
		cnt+=s[i]=='('?1:-1;
		pos=max(pos,{cnt,i});
	}
	puts("2");
	printf("%d %d\n",1,pos.second);
	printf("%d %d\n",pos.second+1,n+n);
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}