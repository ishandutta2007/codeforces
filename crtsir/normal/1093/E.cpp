#include<bits/stdc++.h>
using namespace std;
const int len=1800;
int n,T,a[200003],b[200003],c[200003],p[200003],bit[113][200003];
int sum(int x,int y){y++;
	int ret=0;
	while(y>0){
		ret+=bit[x][y];
		y-=y&-y;
	}
	return ret;
}
void add(int x,int y,int a){y+=2;
	while(y<200003){
		bit[x][y]+=a;
		y+=y&-y;
	}
}
void calc(){
	int la,ra,lb,rb,ans=0;
	scanf("%d%d%d%d",&la,&ra,&lb,&rb);la--;lb--;
	for(int i=lb;i<rb;)
		if(i%len==0&&i+len<=rb){
			ans+=sum(i/len,ra)-sum(i/len,la);
			i+=len;
		}else{
			if(la<=c[i]&&c[i]<ra)
				ans++;
			i++;
		}
	printf("%d\n",ans);
}
void change(){int x,y;
	scanf("%d%d",&x,&y);x--;y--;
	add(x/len,c[x],-1);
	add(y/len,c[y],-1);
	swap(c[x],c[y]);
	add(x/len,c[x],1);
	add(y/len,c[y],1);
}
int main(){cin>>n>>T;
	for(int i=0;i<n;i++)scanf("%d",a+i),a[i]--;
	for(int i=0;i<n;i++)p[a[i]]=i;
	for(int i=0;i<n;i++)scanf("%d",b+i),b[i]--;
	for(int i=0;i<n;i++)c[i]=p[b[i]];
	for(int i=0;i<n;i++)add(i/len,c[i],1);
	while(T--){
		int type;
		scanf("%d",&type);
		if(type==1)
			calc();
		else
			change();
	}
}