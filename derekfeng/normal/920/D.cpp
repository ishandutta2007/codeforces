#include<bits/stdc++.h>
using namespace std;
void add(int &x,int y){
	if(x<0||x>y)x=y;
}
int T,n,V,K,a[5005],b[5005],w;
int f[5005][5005];
int main(){
	scanf("%d%d%d",&n,&K,&V),w=V%K;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i]%K;
	memset(f[0],-1,sizeof(f[0]));
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for(int j=0;j<K;j++)if(f[i-1][j]!=-1)
			add(f[i][(j+b[i])%K],f[i-1][j]+1);
	}
	vector<int>A,B,r,s,t;
	int cur=w,ans=f[n][w];
	int sumA=0,sumB=0;
	if(ans<0){
		puts("NO");
		return 0;
	}
	for(int i=n;i;i--){
		if(f[i-1][(cur+K-b[i])%K]==ans-1&&ans>0){
			cur=(cur+K-b[i])%K,ans--;
			A.push_back(i);
		}else B.push_back(i);
	}
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	if(A.empty()){
		r.push_back(n),s.push_back(n-1),t.push_back(1e9);
		B.pop_back(),A.push_back(n);
		sumA=0,sumB=a[B[0]]+a[n];
		for(int i=1;i<B.size();i++)r.push_back(B[i]),s.push_back(B[0]),t.push_back(1e9),sumB+=a[B[i]];
	}else if(B.empty()){
		sumA=a[A[0]],sumB=0;
		for(int i=1;i<A.size();i++)r.push_back(A[i]),s.push_back(A[0]),t.push_back(1e9),sumA+=a[A[i]];
		A.pop_back(),B.push_back(n);
	}else{
		sumA=a[A[0]],sumB=a[B[0]];
		for(int i=1;i<A.size();i++)r.push_back(A[i]),s.push_back(A[0]),t.push_back(1e9),sumA+=a[A[i]];
		for(int i=1;i<B.size();i++)r.push_back(B[i]),s.push_back(B[0]),t.push_back(1e9),sumB+=a[B[i]];
	}
	if(sumA<V){	
		if(sumA+sumB/K*K<V){
			puts("NO");
			return 0;
		}
		r.push_back(B[0]),s.push_back(A[0]),t.push_back((V-sumA)/K);
	}
	if(sumA>V)r.push_back(A[0]),s.push_back(B[0]),t.push_back((sumA-V)/K);
	puts("YES");
	for(int i=0;i<r.size();i++)printf("%d %d %d\n",t[i],r[i],s[i]);
}