#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int cnt,L[1600004],R[1600004],dat[1600004],lzy[1600004];
int make_tree(int l,int r){
	int id=++cnt;
	if(l==r){
		dat[id]=l-1;
		return id;
	}
	L[id]=make_tree(l,(l+r)/2);
	R[id]=make_tree((l+r)/2+1,r);
	dat[id]=max(dat[L[id]],dat[R[id]]);
	return id;
}
void upd(int id,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		lzy[id]+=x,dat[id]+=x;
		return;
	}
	upd(L[id],l,(l+r)/2,a,b,x),upd(R[id],(l+r)/2+1,r,a,b,x);
	dat[id]=max(dat[L[id]],dat[R[id]])+lzy[id];
}
int qry_max(int id,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return dat[id];
	return max(qry_max(L[id],l,(l+r)/2,a,b),qry_max(R[id],(l+r)/2+1,r,a,b))+lzy[id];
}
int n,K,m;
map<pii,int>mp;
multiset<int>st;
int main(){
	read(n),read(K),read(m);
	make_tree(1,2*n+m);
	for(int i=1;i<=m;i++){
		int x,y,p,add=1;read(x),read(y),p=abs(x-K)+y;
		if(mp[mkp(x,y)]>0){
			st.erase(st.find(p));
			mp[mkp(x,y)]--;
			add=-1;
		}else{
			st.insert(p);
			mp[mkp(x,y)]++;
		}
		upd(1,1,2*n+m,1,p,add);
		if(st.empty()){
			puts("0");continue;
		}
		write(max(0,qry_max(1,1,2*n+m,1,(*st.rbegin()))-n)),puts("");
	}
}