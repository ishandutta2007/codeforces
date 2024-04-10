#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
int n,cnt,L[3300000],R[3300000],siz[3300000];
ll ans[3300000][5];
void push(int id){
	siz[id]=(L[id]>0?siz[L[id]]:0)+(R[id]>0?siz[R[id]]:0);
	siz[id]%=5;
	for(int i=0;i<5;i++)ans[id][i]=0;
	if(L[id])for(int i=0;i<5;i++)ans[id][i]+=ans[L[id]][i];
	int a=L[id]>0?siz[L[id]]:0;
	if(R[id])for(int i=0;i<5;i++)ans[id][(i+a)%5]+=ans[R[id]][i];
}
void add(int l,int r,int id,int pos){
	if(l==r)siz[id]=1,ans[id][0]=pos;
	else{
		if((l+r)/2>=pos){
			if(L[id]==0)L[id]=++cnt;
			add(l,(l+r)/2,L[id],pos);
		}else{
			if(R[id]==0)R[id]=++cnt;
			add((l+r)/2+1,r,R[id],pos);
		}
		push(id);
	}
}
void del(int l,int r,int id,int pos){
	if(l==r)siz[id]=0,ans[id][0]=0;
	else{
		if((l+r)/2>=pos)del(l,(l+r)/2,L[id],pos);
		else del((l+r)/2+1,r,R[id],pos);
		push(id);
	}
}
char buf[6];
int x;
int main(){
	scanf("%d",&n);
	cnt=1;
	while(n--){
		scanf("%s",buf);
		if(*buf=='a')scanf("%d",&x),add(1,INF,1,x);
		if(*buf=='d')scanf("%d",&x),del(1,INF,1,x);
		if(*buf=='s')printf("%I64d\n",ans[1][2]);
	}
}