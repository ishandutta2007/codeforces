#include<bits/stdc++.h>
//#define int long long
const int N=100050;
using namespace std;

struct node{
	int x,y,c;void input(){cin>>x>>y>>c;}
}a[N],b[N];
int n,ANS;

int gh1(int l,int A,int k){
	int nw=0;
	for(int i=l,j=l;i<=n;i=j){
		while(a[i].x==a[j].x){
			if(a[j].c==A)
				nw++;
			j++;
		}
		if(nw>=k)return j-1;
	}
	return n+1;
}

bool chk1(int a,int b,int c,int k){
	int p;
	p=gh1(1,a,k);
	p=gh1(p+1,b,k);
	p=gh1(p+1,c,k);
	return p<=n;
}

bool chk3(int A,int B,int C,int k){
	int p;
	p=gh1(1,A,k);
	int pos=0,nw=0;
	for(int i=1,j=1;i<=n;i=j){
		while(b[i].y==b[j].y){
			if(b[j].x>a[p].x&&b[j].c==B)
				nw++;
			j++;
		}
		if(nw>=k){
			pos=j;break;
		}
	}
	if(!pos)return 0;
	int res=0;
	for(int i=pos;i<=n;i++)
		if(b[i].x>a[p].x&&b[i].c==C)
			res++;
	return res>=k;
}

bool chk(int k){
	if(chk1(1,2,3,k))return 1;
	if(chk1(1,3,2,k))return 1;
	if(chk1(2,1,3,k))return 1;
	if(chk3(1,2,3,k))return 1;
	if(chk3(1,3,2,k))return 1;
	if(chk3(2,1,3,k))return 1;
	if(chk3(2,3,1,k))return 1;
	if(chk3(3,1,2,k))return 1;
	if(chk3(3,2,1,k))return 1;
	return 0;
}

void solve(){
	sort(a+1,a+1+n,[](node x,node y){return x.x<y.x;});
	sort(b+1,b+1+n,[](node x,node y){return x.y<y.y;});
	int l=1,r=n/3,ans=1;while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	ANS=max(ANS,ans);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i].input(),b[i]=a[i];
	for(int i=0;i<4;i++){
		for(int i=1;i<=n;i++)
			a[i]={10-a[i].y+1,a[i].x,a[i].c},b[i]=a[i];
		solve();
	}
	cout<<ANS*3<<endl;
}