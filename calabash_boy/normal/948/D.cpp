#include<bits/stdc++.h>
#define root 0
using namespace std;
const int maxn = 3e5+100;
int cnt[maxn*16];
int ch[maxn*16][2];
int nodecnt;
int ans[maxn];
int a[maxn],p[maxn],n;
int bas[40];
void insert(int val,int flag){
	int now = root;
	for (int i=31;i>=0;i--){
		int bit = val&bas[i];
		bit = bit!=0;
		cnt[now]++;
		if (!ch[now][bit])ch[now][bit] = ++nodecnt;
		now = ch[now][bit];
	}
	cnt[now]++;
}
int search(int val){
	int now = root;
	int res =0;
	for (int i=31;i>=0;i--){
		int bit = val&bas[i];
		bit = bit!=0;
		cnt[now]--;
		if (ch[now][bit]&&cnt[ch[now][bit]]){
			now = ch[now][bit];
		}else{
			now = ch[now][!bit];
			res+=bas[i];
		}
	}
	cnt[now]--;
	return res;
}
void input(){
	bas[0]=1;
	for (int i=1;i<=31;i++){
		bas[i] =bas[i-1]<<1;
	}
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",p+i);
		insert(p[i],i);
	}
}
void solve(){
	for (int i=1;i<=n;i++){
		printf("%d ",search(a[i]));
	}
}
int main(){
	input();
	solve();
	return 0;
}