#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
struct sgt{
	int ls,rs,tag,mn,mx;
}s[N<<1];
char a[N];
char op[N];
int rt,P;
int build(int l,int r){
	int p=++P;
	if(l==r) return p;
	int mid=(l+r)>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
inline int getmn(int p){
	return s[p].mn+s[p].tag;
}
inline int getmx(int p){
	return s[p].mx+s[p].tag;
}
inline void upd(int p){
	s[p].mn=min(getmn(s[p].ls),getmn(s[p].rs));
	s[p].mx=max(getmx(s[p].ls),getmx(s[p].rs));
}
int x;
void chg(int p,int cl,int cr,int pos){
	if(cl==cr){
		s[p].tag+=x;
		return;
	}
	int mid=(cl+cr)>>1;
	if(pos<mid){
		s[s[p].rs].tag+=x;
		chg(s[p].ls,cl,mid,pos);
	}
	else{
		chg(s[p].rs,mid+1,cr,pos);
	}
	upd(p);
}
int n;
int main(){
	int i,j;
	scanf("%d",&n);
	cin>>(op+1);
	int pos=1,s=0;
	rt=build(1,n);
	for(i=1;i<=n;i++){
		if(op[i]=='L'){
			pos=max(pos-1,1);
		}
		else if(op[i]=='R'){
			pos++;
		}
		else if(op[i]=='('){
			if(a[pos]=='(') x=0;
			else if(a[pos]==')') x=2;
			else x=1;
			chg(rt,1,n,pos);
			s+=x;
		}
		else if(op[i]==')'){
			if(a[pos]==')') x=0;
			else if(a[pos]=='(') x=-2;
			else x=-1;
			chg(rt,1,n,pos);
			s+=x;
		}
		else{
			if(a[pos]=='(') x=-1;
			else if(a[pos]==')') x=1;
			else x=0;
			chg(rt,1,n,pos);
			s+=x;
		}
		if(op[i]!='L'&&op[i]!='R') a[pos]=op[i];
		if(s!=0){
			printf("-1 ");
			continue;
		}
		int mx=getmx(rt),mn=getmn(rt);
		if(mn<0){
			printf("-1 ");
			continue;
		}
		printf("%d ",mx);
	}
	return 0;
}