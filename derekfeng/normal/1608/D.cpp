#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
const int G=3,Gi=332748118;
int n_,lg,rev[1100000],A[1100000],B[1100000];
char mp[3]={'?','B','W'};
int num[3][3];
int n;
int mypow(int x,int t){
    int ans=1,res=x;
    for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
    return ans;
}
int fc[300005],inv[300005],pw2[300005];
void init(){
	int N=3e5+4;
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
	for(int i=0;i<=N;i++)ans.push_back(C(N,i));
	return ans;
}
vector<int>poly2(int N){
	vector<int>ans;
	for(int i=0;i<N;i++)ans.push_back(0);
	for(int i=0;i<=N;i++)ans.push_back(C(N,i));
	return ans;
}
vector<int>poly3(int N){
	N*=2;
	return poly1(N);
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
int main(){
	init();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char buf[5];
		scanf("%s",buf);
		int id0,id1;
		for(int j=0;j<3;j++){
			if(mp[j]==buf[0])id0=j;
			if(mp[j]==buf[1])id1=j;
		}
		num[id0][id1]++;
	}
	vector<int>A=poly1(num[0][1]+num[1][0]),B=poly2(num[0][2]+num[2][0]),C=poly3(num[0][0]);
	B=mul(B,C);
	A=mul(A,B);
	vector<int>F;
	for(int i=0;i<num[2][2]*2;i++)F.push_back(0);
	for(auto x:A)F.push_back(x);
	int ans=0;
	if(num[0][1]+num[1][0]+num[1][1]+num[0][2]+num[2][0]+num[2][2]+num[0][0]<F.size())
		ans=F[num[0][1]+num[1][0]+num[1][1]+num[0][2]+num[2][0]+num[2][2]+num[0][0]];
	if(num[1][1]==0&&num[2][2]==0){
		int del=mypow(2,num[0][0]);
		if(num[2][1]==0&&num[2][0]==0&&num[0][1]==0)del=(del+M-1)%M;
		if(num[1][2]==0&&num[1][0]==0&&num[0][2]==0)del=(del+M-1)%M;
		ans=(ans+M-del)%M;
	}
	printf("%d",ans);
}