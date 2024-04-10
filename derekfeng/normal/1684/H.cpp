#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,lg[1000005],N;
char s[1000005];
pii ans[1000005];
int ask(int i,int k){
	for(;;i++){
		k-=s[i]=='1';
		if(k==0)break;
	}
	return i;
}
void sol(int l,int r,int k,int n){
	if(k==n){
		for(int i=l;i<=r;i++)ans[++N]={i,i};
		return;
	}
	if(k==2&&n==3){
		int pos=ask(l,1);
		ans[++N]={l,pos+1};
		for(int i=pos+2;i<=r;i++)ans[++N]={i,i};
		return;
	}
	if(k*3/2>=n){
		int pos=ask(l,1),pos_=ask(l,2);
		ans[++N]={l,pos+1};
		for(int i=pos+2;i<=pos_;i++)ans[++N]={i,i};
		sol(pos_+1,r,k-2,n-3);
		return;
	}
	if((k==4&&n==8)||(k==9&&n==16)){
		int pos=ask(l,1);
		ans[++N]={l,pos+2};
		if(s[pos]=='1'&&s[pos+1]=='0'&&s[pos+2]=='0')sol(pos+3,r,k-1,n-4);
		if(s[pos]=='1'&&s[pos+1]=='0'&&s[pos+2]=='1')sol(pos+3,r,k-2,n-5);
		if(s[pos]=='1'&&s[pos+1]=='1'&&s[pos+2]=='0')sol(pos+3,r,k-2,n-6);
		if(s[pos]=='1'&&s[pos+1]=='1'&&s[pos+2]=='1')sol(pos+3,r,k-3,n-7);
		return;
	}
	if((k==7&&n==11)||(k==10&&n==16)){
		int pos=ask(l,4);
		sol(l,pos,4,8);
		if(pos<r)sol(pos+1,r,k-4,n-8);
		return;
	}
	int pos=ask(l,k/2);
	sol(l,pos,k/2,n/2),sol(pos+1,r,(k+1)/2,n/2);
}
int main(){
	int t;scanf("%d",&t);
	lg[1]=1;for(int i=2;i<=1e6;i++)lg[i]=lg[(i+1)/2]*2;
	while(t--){
		scanf("%s",s+1),n=strlen(s+1),N=0;
		int k=0;for(int i=1;i<=n;i++)k+=s[i]=='1';
		if(k==0){puts("-1");continue;}
		if(k==5){
			int pos=-1;
			for(int i=4;i<=n;i++)
				if(s[i-3]=='1'&&s[i-2]=='1'&&s[i-1]=='1'&&s[i]=='1')
					pos=i;
			if(pos>0){
				for(int i=1;i<=pos-4;i++)ans[++N]={i,i};
				ans[++N]={pos-3,pos};
				for(int i=pos+1;i<=n;i++)ans[++N]={i,i};
			}else{
				for(int i=3;i<=n;i++){
					if(s[i-2]=='1'&&s[i-1]=='0'&&s[i]=='0')
						pos=i;
					if(s[i-2]=='1'&&s[i-1]=='0'&&s[i]=='1')
						pos=i;
				}
				for(int i=1;i<=pos-3;i++)ans[++N]={i,i};
				ans[++N]={pos-2,pos};
				for(int i=pos+1;i<=n;i++)ans[++N]={i,i};
			}
		}else sol(1,n,k,lg[k]);
		printf("%d\n",N);
		for(int i=1;i<=N;i++)printf("%d %d\n",ans[i].fi,ans[i].se);
	}
}