#include<bits/stdc++.h>
using namespace std;
const int T=400;
int a[100003],cnt[100003],n,q,ans[100003],l[100003],r[100003],nw,can,Lst[100003],w[100003],nww[100003],d[100003],tlst[100003],tnxt[100003],idx[100003];
deque<int>v[100003];
bool cmp(int x,int y){
	if(l[x]/T!=l[y]/T)return l[x]<l[y];
	return r[x]<r[y];
}
void add(int x){
	if(cnt[a[x]]==0)nw++;
	cnt[a[x]]++;
}
void del(int x){
	cnt[a[x]]--;
	if(cnt[a[x]]==0)nw--;
}
int L=0,R=-1,qwq=0;
int calc(int x){
	if(v[x].size()==0)return 0;
	if(v[x].size()<3)return 1;
	if(w[v[x][1]]!=w[v[x][v[x].size()-1]])return 0;
	if(2*tnxt[v[x][0]]!=v[x][0]+tnxt[tnxt[v[x][0]]])return 0;
	return 1;
}
int main(){
	memset(Lst,-1,sizeof(Lst));
	memset(d,-1,sizeof(d));
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++){
		if(Lst[a[i]]==-1)
			w[i]=i;
		else{
			if(d[a[i]]==-1||d[a[i]]==i-Lst[a[i]])
				w[i]=w[Lst[a[i]]],d[a[i]]=i-Lst[a[i]];
			else
				w[i]=i,d[a[i]]=-1;
		}
		tlst[i]=Lst[a[i]];
		if(tlst[i]!=-1)tnxt[tlst[i]]=i;
		Lst[a[i]]=i;
	}
	cin>>q;
	for(int i=0;i<q;i++){
		scanf("%d%d",l+i,r+i);
		l[i]--;
		r[i]--;
		idx[i]=i;
	}
	sort(idx,idx+q,cmp);
	for(int i=0;i<q;i++){
		while(R<r[idx[i]])qwq-=calc(a[R+1]),add(++R),v[a[R]].push_back(R),qwq+=calc(a[R]);
		while(R>r[idx[i]])qwq-=calc(a[R]),del(R--),v[a[R+1]].pop_back(),qwq+=calc(a[R+1]);
		while(L<l[idx[i]])qwq-=calc(a[L]),del(L++),v[a[L-1]].pop_front(),qwq+=calc(a[L-1]);
		while(L>l[idx[i]])qwq-=calc(a[L-1]),add(--L),v[a[L]].push_front(L),qwq+=calc(a[L]);
		ans[idx[i]]=nw+(qwq==0);
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]);
}