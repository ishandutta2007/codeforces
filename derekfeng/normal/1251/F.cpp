#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
}
using namespace IO;
typedef long long ll;
int read(){int ret,c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(int x){if(x>9)write(x/10);pchar(x%10+'0');}
const int M=998244353;
const int G=3,Gi=332748118;
int n_,lg,rev[1100000],A[1100000],B[1100000];
int mypow(int x,int t){
    int ans=1,res=x;
    for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
    return ans;
}
int fc[600005],inv[600005],pw2[600005];
void init(){
	int N=6e5+4;
	fc[0]=1;
	for(int i=1;i<N;i++)fc[i]=(ll)fc[i-1]*i%M;
	inv[N-1]=mypow(fc[N-1],M-2);
	for(int i=N-1;i;i--)inv[i-1]=(ll)inv[i]*i%M;
	pw2[0]=1;
	for(int i=1;i<N;i++)pw2[i]=(ll)pw2[i-1]*2%M;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*inv[b]%M*inv[a-b]%M;
}
vector<int>poly1(int N){
	vector<int>ans;
	for(int i=0;i<=N;i++)ans.push_back((ll)C(N,i)*pw2[i]%M);
	return ans;
}
vector<int>poly2(int N){
	N*=2;
	vector<int>ans;
	for(int i=0;i<=N;i++)ans.push_back(C(N,i));
	return ans;
}
void ntt(int *A,int typ){
	for(int i=0;i<n_;i++)if(rev[i]>i)swap(A[i],A[rev[i]]);
    for (int i=0;i<lg;i++){
		int mid=(1<<i);
		int Wn=mypow(typ==1?G:Gi,(M-1)/(mid<<1));
		for(int j=0;j<n_;j+=(mid<<1)){
        	int w=1;
        	for(int k=0;k<mid;k++,w=(ll)w*Wn%M){
        		int x=A[j+k],y=(ll)w*A[j+mid+k]%M;
        		A[j+k]=(x+y)%M,A[j+mid+k]=(x-y+M)%M;
			}
		}
    }
	if(typ<0){
		int inv=mypow(n_,M-2);
		for(int i=0;i<n_;i++)A[i]=(ll)A[i]*inv%M;
	}
}
vector<int>mul(vector<int>&a,vector<int>&b){
	int n=a.size()-1,m=b.size()-1;
	n_=1,lg=0;
	while(n_<=n+m)n_<<=1,lg++;
	for(int i=1;i<n_;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<n_;i++){
		A[i]=B[i]=0;
		if(i<=n)A[i]=a[i];
		if(i<=m)B[i]=b[i];
	}
	ntt(A,1),ntt(B,1);
	for(int i=0;i<n_;i++)A[i]=(ll)A[i]*B[i]%M;
	ntt(A,-1);
	vector<int>ans;
	for(int i=0;i<=n+m;i++)ans.push_back(A[i]);
	return ans;
}
int n,m;
int ans[1200004],num[300004];
vector<int>sol(int l,int r){
	if(r<l)return vector<int>{1};
	if(l==r){
		vector<int>v{1};
		if(num[l]>0)v.push_back(2);
		if(num[l]>1)v.push_back(1);
		return v;
	}
	int md=(l+r)>>1;
	vector<int>A=sol(l,md),B=sol(md+1,r);
	if(A.size()==1)return B;
	if(B.size()==1)return A;
	return mul(A,B);
}
int main(){
	init();
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int x=read();
		num[x]++;
	}
	vector<int>f{1},v;
	int num0=0,num1=0;
	while(m--)v.push_back(read());
	int lst=0;
	sort(v.begin(),v.end());
	for(auto x:v){
		for(int i=lst;i<x;i++){
			if(num[i]>1)num1++;
			else if(num[i]>0)num0++;
		}
		vector<int>Poly1=poly1(num0),Poly2=poly2(num1);
		vector<int>f=mul(Poly1,Poly2);
		for(int i=0;i<f.size();i++)(ans[i+i+2+x+x]+=f[i])%=M;
		lst=x;
	}
	int q=read();
	while(q--){
		int x=read();
		write(ans[x]),pchar('\n');
	}
	output();
}