#include<iostream>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 1048576
#define P 998244353
I void Swap(int&x,int&y){
	int tem=x;
	x=y;
	y=tem;
}
I int Add(int x,int y){
	x+=y;
	return x>=P?x-P:x;
}
I int PowMod(int x,int y){
	int s=1;
	while(y!=0){
		if((y&1)==1){
			s=(L)s*x%P;
		}
		x=(L)x*x%P;
		y>>=1;
	}
	return s;
}
I void NTT(int*A,const int len,const short type){
	int tem=0;
	for(R i=0;i!=len;i++){
		if(i<tem){
			Swap(A[i],A[tem]);
		}
		R j=len;
		do{
			j>>=1;
			tem^=j;
		}while(tem<j);
	}
	static int w[N];
	w[0]=1;
	for(R i=1;i!=len;i<<=1){
		tem=i<<1;
		int omg=PowMod(3,P-1+(P-1)*type/tem);
		for(R j=1;j!=i;j++){
			w[j]=(L)w[j-1]*omg%P;
		}
		for(R j=0;j!=len;j+=tem){
			for(R k=j;k!=i+j;k++){
				int t1=A[k],t2=(L)A[i+k]*w[k-j]%P;
				A[k]=Add(t1,t2);
				A[i+k]=Add(t1,P-t2);
			}
		}
	}
	if(type==-1){
		tem=PowMod(len,P-2);
		for(R i=0;i!=len;i++){
			A[i]=(L)A[i]*tem%P;
		}
	}
}
int a[N],pre[N],suf[N],pa[N],sa[N],c[N];
bool vis[N];
I void Solve(int l,int r){
	if(l+2>r){
		return;
	}
	int mid=l+r>>1;
	static int ta[N],tb[N];
	for(R i=l;i!=r;i++){
		ta[i-l]=tb[i-l]=0;
	}
	for(R i=l;i!=mid;i++){
		ta[i-l]=pa[i];
	}
	for(R i=mid;i!=r;i++){
		tb[i-mid]=sa[i];
	}
	/*printf("L%d %d\n",l,r);
	for(R i=l;i<r;i++){
		printf("%d ",ta[i-l]);
	}
	puts("");
	for(R i=l;i<r;i++){
		printf("%d ",tb[i-l]);
	}
	puts("");*/
	NTT(ta,r-l,1);
	NTT(tb,r-l,1);
	for(R i=l;i!=r;i++){
		ta[i-l]=(L)ta[i-l]*tb[i-l]%P;
	}
	NTT(ta,r-l,-1);
	/*for(int i=l;i<r;i++){
		printf("%d ",ta[i-l]);
	}
	puts("");*/
	for(R i=l;i!=r;i++){
		int&d=c[mid+i];
		d=Add(d,ta[i-l]);
	}
	Solve(l,mid);
	Solve(mid,r);
}
int main(){
	int n,m,p,len=1;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	for(R i=0;i!=m;i++){
		cin>>p;
		vis[p-1+n]=true;
	}
	while(len<n){
		len<<=1;
	}
	len<<=2;
	int ans=0;
	for(R i=1;i!=n<<1;i++){
		pre[i]=pre[i-1]+vis[i];
	}
	for(R i=n*3-1;i>=n;i--){
		suf[i]=suf[i+1]+vis[i];
	}
	for(R i=0;i!=n*3;i++){
		pa[i]=pre[i]=i<n<<1?PowMod(2,pre[i]):0;
		sa[i]=suf[i]=i<n?0:PowMod(2,suf[i]);
	}
	/*for(R i=0;i!=n*3;i++){
		printf("%d ",pa[i]);
	}
	puts("");
	for(R i=0;i!=n*3;i++){
		printf("%d ",sa[i]);
	}
	puts("");*/
	Solve(0,len);
	/*for(R i=0;i!=n*6;i++){
		printf("%d ",c[i]);
	}
	puts("");*/
	for(R i=0;i!=n;i++){
		//printf("C%d %lld\n",i,(c[(i+n<<1)]-(L)pre[i+n]*suf[i+n])%P);
		ans=((L)c[(i+n<<1)]*a[i]+ans)%P;
	}
	for(R i=0;i!=n;i++){
		int l=i+n,r=(n<<1)-1-i;
		//printf("I%d %d %d\n",i,l,r);
		ans=(ans-(L)(l<r?l:r)*a[i])%P;
	}
	int pw=PowMod(2,m);
	ans=(L)(ans+P)*PowMod(pw-1,P-2)%P;
	cout<<ans;
	return 0;
}