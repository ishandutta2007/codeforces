#include<bits/stdc++.h>
using namespace std;
int n,m,q;
set<int>s[200003],t[200003];
struct node{
	bool flg;
	int maxn,minn;
}dat[524288];
node merge(node x,node y){
	node ret;
	ret.flg=x.flg&y.flg;
	ret.maxn=max(x.maxn,y.maxn);
	ret.minn=min(x.minn,y.minn);
	if(x.minn<=y.maxn)
		ret.flg=0;
	return ret;
}
void output(node x){
	cout<<x.minn<<' '<<x.maxn<<' '<<x.flg<<endl;
}
void rebuild(int x){
	node tmp;
	tmp.flg=1;
	if(s[x].size()==0)
		tmp.minn=19260817;
	else
		tmp.minn=(*s[x].begin()); 
	if(t[x].size()==0)
		tmp.maxn=-1;
	else
		tmp.maxn=-(*t[x].begin());
	x+=262144;
	if(tmp.minn<=tmp.maxn)tmp.flg=0;
	dat[x]=tmp;x>>=1;
	while(x){
		dat[x]=merge(dat[x*2],dat[x*2+1]);
		x>>=1;
	}
}
int main(){
	cin>>n>>m>>q;
	for(int i=0;i<524288;i++){
		dat[i].maxn=-1;
		dat[i].minn=19260817;
		dat[i].flg=1;
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		if((x&1)&&(y&1)){
			x>>=1;y>>=1;
			if(t[x].find(-y)!=t[x].end())
				t[x].erase(-y);
			else
				t[x].insert(-y);
		}else if(!(x&1)&&!(y&1)){
			x>>=1;y>>=1;
			if(s[x].find(y)!=s[x].end())
				s[x].erase(y);
			else
				s[x].insert(y);
		}
		rebuild(x);
		if(dat[1].flg)
			printf("YES\n");
		else
			printf("NO\n");
	}
}