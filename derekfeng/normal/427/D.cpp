#include<bits/stdc++.h>
using namespace std;
void reads(string &s){s="";register char ch=getchar();for(;ch==' '||ch=='\n';ch=getchar());for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());}
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}
int n1,n2,N;
string s,t,S;
int sa[10004],sa_[10004],rk[10004],rk_[10004],lcp[10004];
int cur[10004],num[10004],M=122,K;
bool cmp(int a,int b){
	if(rk[a]<rk[b])return 1;if(a+K>N&&b+K>N)return 0;
	if(a+K>N)return 1;return rk[a+K]<rk[b+K];
}
void get_sa_lcp(){
	for(int i=1;i<=N;i++)rk[i]=S[i],num[rk[i]]++;for(int i=1;i<=M;i++)cur[i]=cur[i-1]+num[i-1];for(int i=1;i<=N;i++)sa[++cur[rk[i]]]=i;
	for(K=1;K<N;K<<=1){
		for(int i=1;i<=M;i++)num[i]=0;for(int i=1;i<=N;i++)num[rk[i]]++;
		for(int i=1;i<=M;i++)cur[i]=cur[i-1]+num[i-1];for(int i=N-K+1;i<=N;i++)sa_[++cur[rk[i]]]=i;
		for(int i=1;i<=N;i++){int p=sa[i];if(p-K<1)continue;sa_[++cur[rk[p-K]]]=p-K;}
		for(int i=1;i<=N;i++)sa[i]=sa_[i],rk_[sa[i]]=rk_[sa[i-1]]+cmp(sa[i-1],sa[i]);M=rk_[sa[N]];
		for(int i=1;i<=N;i++)rk[i]=rk_[i];
	}
	for(int i=1;i<=N;i++){
		if(rk[i]==1)lcp[rk[i]]=0;
		else{lcp[rk[i]]=max(lcp[rk[i-1]]-1,1);while(max(i,sa[rk[i]-1])+lcp[rk[i]]-1<=N&&S[i+lcp[rk[i]]-1]==S[sa[rk[i]-1]+lcp[rk[i]]-1])lcp[rk[i]]++;lcp[rk[i]]--;}
	}
}
int h[10004],ans=1e9,a[10004];
int main(){
	reads(s),reads(t),n1=s.size(),n2=t.size();
	S="~"+s+"!"+t,N=S.size()-1;
	get_sa_lcp();
	for(int i=1;i<=n2;i++){
		memset(a,0,sizeof(a));
		int p=rk[n1+1+i],lg;h[p]=lg=n2-i+1,a[n2-i+1]++;
		for(int j=p-1;j;j--)lg=min(lg,lcp[j+1]),h[j]=lg,a[lg]++;
		lg=n2-i+1;for(int j=p+1;j<=N;j++)lg=min(lg,lcp[j]),h[j]=lg,a[lg]++;
		for(int j=n2-i+1;j>=0;j--)a[j]+=a[j+1];
		int len=-1;
		for(int j=1;j<=n2-i+1;j++)if(a[j]==2){
			len=j;
			break;
		}
		if(len<0)continue;
		bool ok=0;
		for(int j=1;j<=n1;j++)
			if(h[rk[j]]>=len){
				ok=1;
				break;
			}
		if(ok)ans=min(ans,len); 
	}
	if(ans>1e6)puts("-1");
	else write(ans);
}