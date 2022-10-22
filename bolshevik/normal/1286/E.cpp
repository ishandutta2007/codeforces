#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
void write(__int128 a){
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=6e5+10,mask=(1ll<<30)-1;
int n,mn[o*4],nxt[o],f[o];long long sm;__int128 ans;char s[o],inp[3];map<int,int> mp;
void modify(int id,int pos,int val,int l=1,int r=n){
	if(l==r){mn[id]=val;return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	mn[id]=min(mn[id<<1],mn[(id<<1)|1]);
}
int query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return mn[id];
	int md=l+r>>1;
	return min(ql<=md?query(id<<1,ql,qr,l,md):mask,md<qr?query((id<<1)|1,ql,qr,md+1,r):mask);
}
int main(){
	scanf("%d",&n);nxt[0]=f[0]=-1;
	for(int i=1,w;i<=n;write(ans+=sm),putchar('\n'),++i){
		scanf("%s%d",inp,&w);modify(1,i,w^=(ans&mask));s[i]=(inp[0]-97+ans)%26+97;
		for(nxt[i]=nxt[i-1];nxt[i]+1&&s[nxt[i]+1]-s[i];nxt[i]=nxt[nxt[i]]);
		++nxt[i];
		if(s[1]==s[i]) ++mp[w],sm+=w;
		if(i==1) continue;
		f[i-1]=(s[nxt[i-1]+1]==s[i]?f[nxt[i-1]]:nxt[i-1]);
		for(int j=nxt[i-1],v;j&&(j=(s[j+1]==s[i]?f[j]:j))>0;j=nxt[j]) --mp[v=query(1,i-j,i-1)],sm-=v;
		for(map<int,int>::iterator iter;(*(iter=--mp.end())).first>w;mp.erase(iter))
			sm-=(*iter).second*1ll*((*iter).first-w),mp[w]+=(*iter).second;
	}
	return 0;
}