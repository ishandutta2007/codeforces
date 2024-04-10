#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,L,R;
int p[26][100005];
int l[505],r[505],cnt[100005],num;
char c[505],s[100005];
int lb[505],rb[505];
ll ans;
int calc(int d,int l,int r){
	return p[d][r]-p[d][l-1];
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=0;i<26;i++)
		for(int j=1;j<=n;j++)p[i][j]=p[i][j-1]+(i+'a'==s[j]);
	scanf("%d%d%d",&K,&L,&R);
	for(int i=1;i<=K;i++){
		char buf[3];
		scanf("%s%d%d",buf,&l[i],&r[i]);
		c[i]=buf[0]-'a';
	}
	cnt[0]=1e5;
	for(int i=1;i<=K;i++)lb[i]=1,rb[i]=0;
	for(int i=1;i<=n;i++){
		bool has_i=0;
		for(int j=1;j<=K;j++){
			while(rb[j]<i&&calc(c[j],rb[j]+1,i)>=l[j]){
				rb[j]++;
				if(rb[j]!=i&&L<=cnt[rb[j]]&&cnt[rb[j]]<=R)num--;
				cnt[rb[j]]++;
				if(rb[j]!=i&&L<=cnt[rb[j]]&&cnt[rb[j]]<=R)num++;
			}
			while(lb[j]<=i&&calc(c[j],lb[j],i)>r[j]){
				if(lb[j]!=i&&L<=cnt[lb[j]]&&cnt[lb[j]]<=R)num--;
				cnt[lb[j]]--;
				if(lb[j]!=i&&L<=cnt[lb[j]]&&cnt[lb[j]]<=R)num++;
				lb[j]++;
			}
		}
		if(L<=cnt[i]&&cnt[i]<=R)num++;
		ans+=num;
	}
	printf("%lld",ans);
}