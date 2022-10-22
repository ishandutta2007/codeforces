#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,q,cnt;
map<pii,bool>mp;
set<int>sta[200004],stb[200004];
int mn[524300],mx[524300];
bool ok[524300];
void pushup(int i){
	ok[i]=ok[i<<1]&ok[i<<1|1]&(mn[i<<1]>mx[i<<1|1]);
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
	mx[i]=max(mx[i<<1],mx[i<<1|1]);
}
void upd(int i,int l,int r,int p){
	if(l==r){
		mn[i]=sta[l].empty()?1e9:(*sta[l].begin());
		mx[i]=stb[l].empty()?0:(*stb[l].rbegin());
		ok[i]=mn[i]>mx[i];
	}else{
		int md=(l+r)>>1;
		if(p<=md)upd(i<<1,l,md,p);
		else upd(i<<1|1,md+1,r,p);
		pushup(i);
	}
}
void add(int r,int c){
	int R=(r+1)/2,C=(c+1)/2;
	if(mp[{R*2-1,C*2-1}])sta[R].erase(C);
	if(mp[{R*2,C*2}])stb[R].erase(C);
	mp[{r,c}]=1;
	if(mp[{R*2-1,C*2-1}]&&mp[{R*2,C*2}])cnt++;
	else if(mp[{R*2-1,C*2-1}])sta[R].insert(C);
	else stb[R].insert(C);
	upd(1,1,n,R);
}
void del(int r,int c){
	int R=(r+1)/2,C=(c+1)/2;
	if(mp[{R*2-1,C*2-1}]&&mp[{R*2,C*2}])cnt--;
	else if(mp[{R*2-1,C*2-1}])sta[R].erase(C);
	else stb[R].erase(C);
	mp[{r,c}]=0;
	if(mp[{R*2-1,C*2-1}])sta[R].insert(C);
	if(mp[{R*2,C*2}])stb[R].insert(C);
	upd(1,1,n,R);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<524300;i++)ok[i]=1,mn[i]=1e9,mx[i]=0;
	while(q--){
		int r,c;scanf("%d%d",&r,&c);
		if(mp[{r,c}])del(r,c);
		else add(r,c);
		puts((cnt==0&&ok[1])?"YES":"NO");
	}
}