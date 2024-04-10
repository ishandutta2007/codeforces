#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,k;
int sa[N],rk[N],tmp[N<<1],cnt[N],h[N];
int a[N];
int st[N][20],lg[N];
void SA(){
	int i,j,num=m+200;
	for(i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	for(i=2;i<=num;i++) cnt[i]+=cnt[i-1];
	for(i=1;i<=n;i++) sa[++cnt[rk[i]-1]]=i;
	for(j=1;j<n;j<<=1){
		for(i=0;i<=num;i++) cnt[i]=0;
		for(i=1;i<=n;i++) cnt[rk[i]]++;
		for(i=2;i<=num;i++) cnt[i]+=cnt[i-1];
		for(i=n-j+1;i<=n;i++) tmp[++cnt[rk[i]-1]]=i;
		for(i=1;i<=n;i++)
			if(sa[i]>j) tmp[++cnt[rk[sa[i]-j]-1]]=sa[i]-j;
		for(i=1;i<=n;i++) sa[i]=tmp[i];
		for(i=1;i<=n;i++) tmp[i]=rk[i];
		num=0;
		for(i=1;i<=n;i++)
			rk[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+j]==tmp[sa[i-1]+j])?num:++num);
	}
	for(i=1;i<=n;i++){
		if(rk[i]==1) continue;
		h[rk[i]]=max(h[rk[i-1]]-1,0);
		int x=sa[rk[i]-1];
		while(i+h[rk[i]]<=n&&a[i+h[rk[i]]]==a[x+h[rk[i]]]) h[rk[i]]++;
	}
	for(i=1;i<=n;i++) st[i][0]=h[i];
	for(j=1;(1<<j)<n;j++){
		for(i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	}
}
string s[N];
int len[N];
int pos[N];
ll ans[N];
inline int qmin(int l,int r){
	if(l>r) return len[sa[r]];
	int len=lg[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);
}
int q[N],hd,tl;
struct seg{
	int l,r,w;
	inline seg(int l,int r,int w):l(l),r(r),w(w){}
};
vector<seg> v;
int main(){
	int i,j;
	cin>>m>>k;
	lg[1]=0;for(i=2;i<N;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	for(i=1;i<=m;i++){
		cin>>s[i];int l=s[i].length();
		for(j=0;j<l;j++){
			a[++n]=s[i][j]-'a'+m;
			pos[n]=i;len[n]=l-j;
		}
		a[++n]=i;
	}
	a[n--]=0;
	SA();
	memset(cnt,0,sizeof(cnt));
	int p=m,ck=0;
	for(i=m;i<=n;i++){
		int x=pos[sa[i]];
		if(!cnt[x]) ck++;
		cnt[x]++;
		while(ck>=k){
			if(ck==k) v.push_back(seg(p,i,qmin(p+1,i)));
			if(cnt[pos[sa[p]]]==1){
				if(ck==k) break;
				ck--;
			}
			cnt[pos[sa[p]]]--;p++;
		}
	}
//	for(auto x:v) cout<<x.l<<" "<<x.r<<" "<<x.w<<endl;
	p=0;
	for(i=m;i<=n;i++){
		while(hd<tl&&v[q[hd]].r<i) hd++;
		while(p<v.size()&&v[p].l<=i){
			while(hd<tl&&v[p].w>=v[q[tl-1]].w) tl--;
			q[tl++]=p;
			p++;
		}
		if(hd==tl) continue;
		ans[pos[sa[i]]]+=v[q[hd]].w;
	}
	for(i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}