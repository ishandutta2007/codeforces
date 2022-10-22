#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6,MOD=1e9+7;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
struct Ari{ int l,r,d; };
struct Pam{
	struct Node{
		int s[26],fa,len,top,delta;
	}t[N];
	int top;
	inline int new_node(){
		t[++top]=(Node){{},0,0,0,0};
		return top;
	}
	Pam(){
		top=-1; new_node(); new_node();
		t[0].fa=t[1].fa=1;
		t[0].len=0; t[1].len=-1;
		t[0].delta=t[1].delta=-1;
	}	
	int get_fa(int p,int s[],int n){
		while(t[p].len==n-1||s[n]!=s[n-t[p].len-1]) p=t[p].fa;
		return p;
	}
	int extend(int p,int s[],int n){
		int c=s[n]; p=get_fa(p,s,n);
		if(t[p].s[c]==0){
			int x=new_node();
			t[x].fa=t[get_fa(t[p].fa,s,n)].s[c];
			t[x].len=t[p].len+2;
			t[x].delta=t[x].len-t[t[x].fa].len;
			t[x].top=(t[x].delta==t[t[x].fa].delta?t[t[x].fa].top:t[x].fa);
			t[p].s[c]=x;
//			printf("{%d %d %d %d %d}",p,x,t[x].fa,t[x].len,t[x].delta);
		}
		return t[p].s[c];
	}
	vector<Ari> get_border(int x){
		vector<Ari> ret;
		for(;x>1;x=t[x].top)
			ret.push_back((Ari){t[t[x].top].len+t[x].delta,t[x].len,t[x].delta});
		return ret;
	}		
}pam;
map<pair<int,int>,int> mp[N];
int a[N],f[N];
char s[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n/2;++i){
		a[i+i-1]=s[i]-'a';
		a[i+i]=s[n-i+1]-'a';
	}
//	for(int i=1;i<=n;++i) printf("%d",a[i]); puts("");
	int last=1; f[0]=1;
	for(int i=1;i<=n;++i){
		last=pam.extend(last,a,i);
		if(i&1) continue;
		vector<Ari> g=pam.get_border(last);
		for(int j=0;j<g.size();++j){
			Ari d=g[j];
			if(~d.d&1){
				if(d.l&1) continue;
			}else{
				if(d.l&1) d.l+=d.d;
				if(d.r&1) d.r-=d.d;
				d.d<<=1;
				if(d.l>d.r) continue;
			}
//			printf("[%d %d %d %d]\n",i,d.l,d.r,d.d);
			
			mp[i][make_pair(d.l,d.d)]=mo1(f[i-d.l]+(d.r-d.d>=d.l?mp[i-d.d][make_pair(d.l,d.d)]:0));
			mo(f[i]+=mp[i][make_pair(d.l,d.d)]);
		}
//		printf("<%d %d>\n",i,f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}