#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
char a[N];
struct sgt{
	int l,r,ls,rs;
	int x[3][3];
}s[3*N];
int rt,P;
int build(int l,int r){
	int p=++P;
	s[p].l=l;s[p].r=r;
	memset(s[p].x,0x3f,sizeof(s[p].x));
	if(l==r) return p;
	int mid=l+r>>1;
	s[p].ls=build(l,mid);
	s[p].rs=build(mid+1,r);
	return p;
}
inline void upd(int p){
	int i,j,k;
	memset(s[p].x,0x3f,sizeof(s[p].x));
	for(i=0;i<3;i++){
		for(k=0;k<3;k++)
			for(j=0;j<3;j++)
				s[p].x[i][j]=min(s[p].x[i][j],s[s[p].ls].x[i][k]+s[s[p].rs].x[k][j]);
	}
}
void chg(int p,int pos){
	if(s[p].l==s[p].r){
		memset(s[p].x,0x3f,sizeof(s[p].x));
		for(int i=0;i<3;i++)
			for(int j=i;j<3;j++)
				s[p].x[i][j]=0;
		int c=a[s[p].l]-'a';
		s[p].x[c][c]=1;
		return;
	}
	int mid=s[p].l+s[p].r>>1;
	if(pos<=mid) chg(s[p].ls,pos);
	else chg(s[p].rs,pos);
	upd(p);
}
int main(){
	int i,j;
	cin>>n>>m;
	cin>>(a+1);
	rt=build(1,n);
	for(i=1;i<=n;i++) chg(rt,i);
	for(i=1;i<=m;i++){
		int pos;char x;cin>>pos>>x;
		a[pos]=x;
		chg(rt,pos);
		cout<<s[rt].x[0][2]<<endl;
	}
	return 0;
}