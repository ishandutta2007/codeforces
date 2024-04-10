#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
char str[2005],beg[2005],ed[2005]; 
ull base=229,ha[2005],jie[2005],len,starter,ender,l1,l2,st[2005],tl[2005],cnt1,cnt2;
ull id(int l,int r){
	if(!l)return ha[r];
	return ha[r]-ha[l-1]*jie[r-l+1];
}
unordered_set<ull> setter;
signed main(){
	cin>>str>>beg>>ed;
	ha[0]=str[0],jie[0]=1;
	len=strlen(str);
	for(int i=1;i<len;i++){
		jie[i]=jie[i-1]*base;
		ha[i]=ha[i-1]*base+str[i];
	}
	starter=beg[0],l1=strlen(beg);
	for(int i=1;i<l1;i++)starter=starter*base+beg[i];
	ender=ed[0],l2=strlen(ed);
	for(int i=1;i<l2;i++)ender=ender*base+ed[i];
	for(int i=l1-1;i<len;i++){
		if(id(i-l1+1,i)==starter)st[++cnt1]=i;
	}
	for(int i=l2-1;i<len;i++){
		if(id(i-l2+1,i)==ender)tl[++cnt2]=i;
	}
	for(int i=1;i<=cnt1;i++){
		for(int j=1;j<=cnt2;j++){
			if(st[i]-l1+1>tl[j]-l2+1||st[i]>tl[j])continue;
			setter.insert(id(st[i]-l1+1,tl[j]));
		}
	}
	cout<<setter.size();
	return 0;
}