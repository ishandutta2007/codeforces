#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
const int T=320,BT=320;
struct EXBlock{
	int a[N],f[N],block_id[N],top_block;
	struct Block{
		int *a,*f,left,right,id,tag;
		bool flag;
		void update(){
			flag=1;
			for(int i=left;i<=right;++i){
				if(i-a[i]<left) f[i]=i;
				else f[i]=f[i-a[i]],flag=0;
			}
		}
		void init(int* _f,int* _a,int _left,int _right,int _id){
			left=_left,right=_right,id=_id,a=_a,f=_f; tag=0; flag=0;
			update();
		}
		void change(int x,int y,int _tag){
			if(y<left||x>right) return;
			if(x<=left&&right<=y&&flag){ tag=min(tag+_tag,right); return; }
			for(int i=max(x,left);i<=min(y,right);++i)
				a[i]=min(a[i]+_tag,right);
			update();
		}
		int fa(int x){
			if(flag) return max(1,x-a[x]-tag);
			else return max(1,x-a[x]);
		}
		int jump_out(int x){
			if(flag) return max(1,x-a[x]-tag);
			return max(1,f[x]-a[f[x]]);
		}
	}b[BT+5];
	void init(int n,int *_a){
		for(int i=1;i<=n;++i) a[i]=_a[i];
		for(int i=1;(i-1)*T+1<=n;++i){
			b[i].init(f,a,(i-1)*T+1,min(n,i*T),i);
			for(int j=b[i].left;j<=b[i].right;++j)
				block_id[j]=i;
		}
		top_block=block_id[n];
	}
	void change(int x,int y,int tag){
		for(int i=1;i<=top_block;++i)
			b[i].change(x,y,tag);
	}
	int lca(int x,int y){
		while(b[block_id[x]].jump_out(x)!=b[block_id[y]].jump_out(y)){
			if(x<y) swap(x,y);
			x=b[block_id[x]].jump_out(x);
		}
		while(x!=y){
			if(x<y) swap(x,y);
			x=b[block_id[x]].fa(x);
		}
		return x;
	}
}b;
int a[N];
int main(){
	int n,q; scanf("%d%d",&n,&q);
	for(int i=2;i<=n;++i) scanf("%d",&a[i]),a[i]=i-a[i];
	b.init(n,a);
	while(q--){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			int tag; scanf("%d",&tag);
			b.change(x,y,tag);
		}else{
			printf("%d\n",b.lca(x,y));
		}
	}
	return 0;
}