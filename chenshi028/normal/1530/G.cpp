#include<cstdio>
#include<utility>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
const int o=2010;
int T,n,k,ca,cb,pa[o],pb[o],s[o],aa,ab;char a[o],b[o];pair<int,int> ansa[o*5],ansb[o*5];
inline void rev(int *p,pair<int,int>&ans,int l,int r,int rd){
	s[0]=p[0];for(int i=1;i<=r;++i) s[i]=s[i-1]+1+p[i];
	if(rd<=p[l]) ans=make_pair((l?s[l-1]+2:1)+rd,s[r-1]+1);
	else ans=make_pair(s[l]+1,s[r-1]+1+rd-p[l]);
	for(int i=l,j=r;i<j;++i,--j) p[i]^=p[j]^=p[i]^=p[j];
	p[r]+=p[l]-rd;p[l]=rd;
}
inline void cano(int*p,pair<int,int>*ans,int&cnt){
	for(int i=ca-k;i>1;--i) rev(p,ans[++cnt],i,i+k,p[i]+p[i+k]);
	for(int i=1;i<=k+1;++i) rev(p,ans[++cnt],0,k,p[0]+p[k]),rev(p,ans[++cnt],1,k+1,(k&1)?p[k+1]:0);
}
void slv(){
	read(n);read(k);scanf("%s",a+1);scanf("%s",b+1);
	for(int i=1,j=pa[0]=ca=0;i<=n;++i,pa[ca]=j) if(a[i]==48) ++j;else ++ca,j=0;
	for(int i=1,j=pb[0]=cb=0;i<=n;++i,pb[cb]=j) if(b[i]==48) ++j;else ++cb,j=0;
	bool tag=1;for(int i=1;i<=n;++i) tag&=(a[i]==b[i]);if(tag){printf("0\n");return;}
	if(!k||ca!=cb||ca<k){printf("-1\n");return;}
	if(k==ca){
		bool flg=1;
		for(int i=1;i<k;++i) flg&=(pa[i]==pb[i]);
		if(flg){
			printf("2\n");
			write(pa[0]+1);putchar(' ');write(n);putchar('\n');write(pb[0]+1);putchar(' ');write(n);putchar('\n');
			return;
		}
		for(int i=flg=1;i<k;++i) flg&=(pa[i]==pb[k-i]);
		if(flg){printf("1\n");write(Min(pb[0],pa[0])+1);putchar(' ');write(n-Min(pa[k],pb[k]));putchar('\n');return;}
		printf("-1\n");
		return;
	}
	aa=0;cano(pa,ansa,aa);
	ab=0;cano(pb,ansb,ab);
	if(k%2==0&&(pa[0]-pb[0]||pa[k+1]-pb[k+1])){printf("-1\n");return;}
	write(aa+ab);putchar('\n');
	for(int i=1;i<=aa;++i) write(ansa[i].first),putchar(' '),write(ansa[i].second),putchar('\n');
	for(int i=ab;i;--i) write(ansb[i].first),putchar(' '),write(ansb[i].second),putchar('\n');
}
int main(){for(read(T);T--;) slv();return 0;}