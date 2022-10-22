#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const int N=2e4+5;
int dp0[N],dp1[N],a[N];
stack<int> stk;
int n,k;
inline int get(pii f,int x){
	return x*f.fr+f.sc;
}
struct sgt{
	int l,r,ls,rs;
	pii w;
}s[N*100];
int rt[N],P;
inline int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	s[p].w={0,inf};
	s[p].ls=s[p].rs=0;
	return p;
}
inline int copy(int p){
	int np=++P;s[np]=s[p];
	return np;
}
void ins(int p,pii w){
	if(s[p].l==s[p].r){
		if(get(w,s[p].l)<get(s[p].w,s[p].l))
			s[p].w=w;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(w.fr<s[p].w.fr){
		if(get(w,mid)<get(s[p].w,mid)){
			if(!s[p].ls) s[p].ls=build(s[p].l,mid);
			else s[p].ls=copy(s[p].ls);
			ins(s[p].ls,s[p].w);
			s[p].w=w;
		}
		else{
			if(!s[p].rs) s[p].rs=build(mid+1,s[p].r);
			else s[p].rs=copy(s[p].rs);
			ins(s[p].rs,w);
		}
	}
	else{
		if(get(w,mid)<get(s[p].w,mid)){
			if(!s[p].rs) s[p].rs=build(mid+1,s[p].r);
			else s[p].rs=copy(s[p].rs);
			ins(s[p].rs,s[p].w);
			s[p].w=w;
		}
		else{
			if(!s[p].ls) s[p].ls=build(s[p].l,mid);
			else s[p].ls=copy(s[p].ls);
			ins(s[p].ls,w);
		}
	}
}
int qry(int p,int pos){
	if(!p) return inf;
	if(s[p].l==s[p].r)
		return get(s[p].w,pos);
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid) return min(qry(s[p].ls,pos),get(s[p].w,pos));
	else return min(qry(s[p].rs,pos),get(s[p].w,pos));
}
pii q[N];
int hd[N],tl[N];
int main(){
	cerr<<(sizeof(s)>>20)<<endl;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	memset(dp0,0x3f,sizeof(dp0));
	a[0]=inf;
	dp0[0]=0;
	for(j=1;j<=k;j++){
		memset(dp1,0x3f,sizeof(dp1));
		P=0;
		while(!stk.empty()) stk.pop();
		rt[0]=build(1,n);
		stk.push(0);
		for(i=1;i<=n;i++){
			q[i]={i-1,dp0[i-1]};hd[i]=tl[i]=i;
			while(!stk.empty()&&a[i]>a[stk.top()]){
				int u=stk.top();
				if(tl[u]-hd[u]>tl[i]-hd[i]){
					for(int t=hd[i];t<=tl[i];t++){
						while(hd[u]<tl[u]&&
						ll(q[t].sc-q[tl[u]].sc)*(q[tl[u]].fr-q[tl[u]-1].fr)<
						ll(q[tl[u]].sc-q[tl[u]-1].sc)*(q[t].fr-q[tl[u]].fr)) tl[u]--;
						q[++tl[u]]=q[t];
					}
					hd[i]=hd[u];
					tl[i]=tl[u];
				}
				else{
					for(int t=tl[u];t>=hd[u];t--){
						while(hd[i]<tl[i]&&
						ll(q[hd[i]].sc-q[t].sc)*(q[hd[i]+1].fr-q[hd[i]].fr)>
						ll(q[hd[i]+1].sc-q[hd[i]].sc)*(q[hd[i]].fr-q[t].fr)) hd[i]++;
						q[--hd[i]]=q[t];
					}
				}
				stk.pop();
			}
			int l=hd[i],r=tl[i];
			while(l<r){
				int mid=l+r>>1;
				if(q[mid].sc-q[mid].fr*a[i]<q[mid+1].sc-q[mid+1].fr*a[i]) r=mid;
				else l=mid+1;
			}
			//for(int t=hd[i];t<=tl[i];t++) cerr<<q[t].fr<<","<<q[t].sc<<" ";cerr<<endl;
			int w=q[l].sc-q[l].fr*a[i];
			rt[i]=copy(rt[stk.top()]);
			ins(rt[i],{a[i],w});
			dp1[i]=qry(rt[i],i);
			//cerr<<i<<" "<<j<<" "<<w<<" "<<dp1[i]<<endl;
			stk.push(i);
		}
		memcpy(dp0,dp1,sizeof(dp1));
	}
	cout<<dp1[n];
	return 0;
}