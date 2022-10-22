#include<cstdio>
#include<vector>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=2e5+10,dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
int n,m,k,a[o];bool flg;vector<int> v[o];
inline int hsh(int x,int y,int z){return (x-1)*m*k+(y-1)*k+z;}
inline bool chk(int x,int y,int z){return 1<=x&&x<=n&&1<=y&&y<=m&&1<=z&&z<=k;}
void del(int x,int y,int z);
void ins(int x,int y,int z,int d,int col){
	if(flg) return;
	int i=hsh(x,y,z);
	if(!chk(x,y,z)){if(col){printf("-1");flg=1;}return;}
	if(!col){if(a[i]>0) del(x,y,z);a[i]=0;ins(x+dx[d],y+dy[d],z+dz[d],d,col);}
	else if(a[i]==-1||a[i]==col) a[i]=col,v[i].push_back(d);
	else if(!a[i]) ins(x+dx[d],y+dy[d],z+dz[d],d,col);
	else del(x,y,z),a[i]=0,ins(x+dx[d],y+dy[d],z+dz[d],d,col);
}
void del(int x,int y,int z)
{for(int i=hsh(x,y,z),j;!v[i].empty();ins(x+dx[j],y+dy[j],z+dz[j],j,a[i])) j=v[i].back(),v[i].pop_back();}
int main(){
	read(n);read(m);read(k);
	for(int i=n*m*k;i;--i) a[i]=-1;
	for(int i=1;i<=m;++i) for(int j=1,$;j<=k;++j) read($),ins(1,i,j,0,$);
	for(int i=1;i<=m;++i) for(int j=1,$;j<=k;++j) read($),ins(n,i,j,1,$);
	for(int i=1;i<=n;++i) for(int j=1,$;j<=k;++j) read($),ins(i,1,j,2,$);
	for(int i=1;i<=n;++i) for(int j=1,$;j<=k;++j) read($),ins(i,m,j,3,$);
	for(int i=1;i<=n;++i) for(int j=1,$;j<=m;++j) read($),ins(i,j,1,4,$);
	for(int i=1;i<=n;++i) for(int j=1,$;j<=m;++j) read($),ins(i,j,k,5,$);
	if(flg) return 0;
	for(int i=1;i<=n*m*k;++i) if(a[i]==-1) printf("0 ");else printf("%d ",a[i]);
	return 0;
}