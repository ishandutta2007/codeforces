#include<bits/stdc++.h>
using namespace std;
int n,a[100003],m;
struct node{
	int a[2][2][23];
	node(){
		memset(a,192,sizeof(a));
	}
}dat[262144],emp;
node merge(node x,node y){
	node ret;
	for(int lx=0;lx<2;lx++)
		for(int rx=0;rx<2;rx++)
			for(int ly=0;ly<2;ly++)
				for(int ry=0;ry<2;ry++)
					for(int i=0,j=0;i+j<=21;){
						if(i+j||!(rx&ly))
							ret.a[lx][ry][i+j-(rx&ly)]=max(ret.a[lx][ry][i+j-(rx&ly)],x.a[lx][rx][i]+y.a[ly][ry][j]);
						if(x.a[lx][rx][i]+y.a[ly][ry][j+1]<x.a[lx][rx][i+1]+y.a[ly][ry][j])
							i++;
						else
							j++;
					}
	return ret;
}
node query(int _l,int _r,int l,int r,int k){
	if(_l>r||_r<l)return emp;
	if(l<=_l&&_r<=r)return dat[k];
	return merge(query(_l,_l+_r>>1,l,r,k<<1),query(_l+_r+1>>1,_r,l,r,k<<1|1));
}
int main(){
	emp.a[0][0][0]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++){
		dat[i+131072].a[0][0][0]=0;
		dat[i+131072].a[1][1][1]=a[i];
	}
	for(int i=131071;i>0;i--)
		dat[i]=merge(dat[i<<1],dat[i<<1|1]);
	scanf("%d",&m);
	while(m--){
		int tp;
		scanf("%d",&tp);
		if(tp==0){
			int i,val;
			scanf("%d%d",&i,&val);i--;
			dat[i+131072].a[1][1][1]=val;
			i=(i+131072>>1);
			while(i)
				dat[i]=merge(dat[i<<1],dat[i<<1|1]),
				i>>=1;
		}else{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);l--;r--;
			node res=query(0,131071,l,r,1);
			int ans=0;
			for(l=0;l<2;l++)
				for(r=0;r<2;r++)
					for(int i=0;i<=k;i++)
						ans=max(ans,res.a[l][r][i]);
			printf("%d\n",ans);
		}
	}
}