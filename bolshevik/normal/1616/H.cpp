#include<cstdio>
using namespace std;
const int o=5e6,E=(1<<30)-1,MOD=998244353;
int n,x,a,cnt,rt,s[o],ls[o],rs[o],pw[o];
void modify(int&id,int pos,int val,int l=0,int r=E){
	if(!id) id=++cnt;
	s[id]+=val;
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify(ls[id],pos,val,l,md);
	else modify(rs[id],pos,val,md+1,r);
}
inline int z(int id){return ((pw[s[id]]-pw[s[ls[id]]]-pw[s[rs[id]]]+1)%MOD+MOD)%MOD;}
int query(int id1,int id2,int dep){
	if(!id1||!id2) return pw[s[id1|id2]];
	if(dep<0) if(id1^id2) return pw[s[id1]]*1ll*pw[s[id2]]%MOD;else return pw[s[id1]];
	if(!((x>>dep)&1))
		if(id1^id2) return (((query(ls[id1],ls[id2],dep-1)+query(rs[id1],rs[id2],dep-1))%MOD+(z(id1)+(z(id2)))%MOD)%MOD+MOD-1)%MOD;
		else return ((query(ls[id1],ls[id2],dep-1)+query(rs[id1],rs[id2],dep-1))%MOD+MOD-1)%MOD;
	if(id1==id2) return query(ls[id1],rs[id2],dep-1);
	return query(ls[id1],rs[id2],dep-1)*1ll*query(rs[id1],ls[id2],dep-1)%MOD; 
}
int main(){
	scanf("%d%d",&n,&x);
	for(int i=pw[0]=1;i<=n;++i) pw[i]=pw[i-1]*2%MOD;
	for(int i=1;i<=n;++i) scanf("%d",&a),modify(rt,a,1);
	printf("%d",(query(rt,rt,29)+MOD-1)%MOD);
	return 0;
}