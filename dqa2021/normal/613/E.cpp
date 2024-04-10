#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int upd(int x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
inline void add(int &x,ll y){x=(x+y)%mod;}


char mp[2][2010];
char str[2010],rts[2010];
int n,k;
int ans;


namespace H{

const int M1=1e9+9,M2=998244353,B1=29,B2=31;
int p1[2010],p2[2010];
int str_h1[2010],str_h2[2010];
int rts_h1[2010],rts_h2[2010];
int mp0_h1[2010],mp0_h2[2010];
int mp1_h1[2010],mp1_h2[2010];
void prepare(){
	int t=max(n,k);
	p1[0]=p2[0]=1;
	for (int i=1;i<=t;i++){
		p1[i]=1LL*p1[i-1]*B1%M1;
		p2[i]=1LL*p2[i-1]*B2%M2;
	}
}
void init(char *str,int n,int *h1,int *h2){
	for (int i=1;i<=n;i++){
		h1[i]=(1LL*h1[i-1]*B1+str[i]-'a'+1)%M1;
		h2[i]=(1LL*h2[i-1]*B2+str[i]-'a'+1)%M2;
	}
}
int gethash(int l,int r,int *h,int M,int *p){
	int res=(h[r]-1LL*h[l-1]*p[r-l+1])%M;
	return res<0?res+M:res;
}
bool check(int *A_h1,int *A_h2,int l,int r,int *B_h1,int *B_h2,int L,int R){
	return gethash(l,r,A_h1,M1,p1)==gethash(L,R,B_h1,M1,p1)
		 &&gethash(l,r,A_h2,M2,p2)==gethash(L,R,B_h2,M2,p2);
}

}
using namespace H;


int P[2][2010][2010],Q[2][2010][2010];


int main()
{
	scanf("%s%s%s",mp[0]+1,mp[1]+1,str+1);
	n=strlen(mp[0]+1); k=strlen(str+1);
	for (int i=1;i<=k;i++) rts[k-i+1]=str[i];
	if (k==1){
		for (int i=1;i<=n;i++){
			if (mp[0][i]==str[1]) ans++;
			if (mp[1][i]==str[1]) ans++;
		}
		printf("%d\n",ans);
		return 0;
	}
	if (k==2){
		for (int i=1;i<=n;i++){
			if (mp[0][i]==str[1]){
				if (mp[1][i]==str[2]) ans++;
				if (mp[0][i+1]==str[2]) ans++;
				if (mp[0][i-1]==str[2]) ans++;
			}
			if (mp[1][i]==str[1]){
				if (mp[0][i]==str[2]) ans++;
				if (mp[1][i+1]==str[2]) ans++;
				if (mp[1][i-1]==str[2]) ans++;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	
	prepare();
	init(mp[0],n,mp0_h1,mp0_h2);
	init(mp[1],n,mp1_h1,mp1_h2);
	init(str,k,str_h1,str_h2);
	init(rts,k,rts_h1,rts_h2);
	
	for (int i=1;i<=n;i++){
		char A=str[1],B=str[2],&C=mp[0][i],&D=mp[1][i];
		if (A==C) add(P[0][i][1],1);
		if (A==D) add(P[1][i][1],1);
		if (A==C&&B==D) add(P[1][i][2],1);
		if (A==D&&B==C) add(P[0][i][2],1);
		for (int j=2;j<i&&j*2<k;j++){
			A=str[j*2+1],B=str[j*2+2];
			bool from0=check(rts_h1,rts_h2,k-j+1,k,mp1_h1,mp1_h2,i-j,i-1)&&check(str_h1,str_h2,j+1,j+j,mp0_h1,mp0_h2,i-j,i-1);
			bool from1=check(rts_h1,rts_h2,k-j+1,k,mp0_h1,mp0_h2,i-j,i-1)&&check(str_h1,str_h2,j+1,j+j,mp1_h1,mp1_h2,i-j,i-1);
			if (A==C&&from0)
				add(P[0][i][j*2+1],1);
			if (A==D&&from1)
				add(P[1][i][j*2+1],1);
			if (A==C&&B==D&&from0)
				add(P[1][i][j*2+2],1);
			if (A==D&&B==C&&from1)
				add(P[0][i][j*2+2],1);
		}
		if (i==1) continue;
		for (int j=2;j<=k;j++){
			A=str[j],B=str[j-1];
			if (A==C) add(P[0][i][j],P[0][i-1][j-1]);
			if (A==D) add(P[1][i][j],P[1][i-1][j-1]);
			if (B==C&&A==D) add(P[1][i][j],P[0][i-1][j-2]);
			if (B==D&&A==C) add(P[0][i][j],P[1][i-1][j-2]);
		}
	}
	for (int i=1;i<=n;i++){
		char A=rts[1],B=rts[2],&C=mp[0][i],&D=mp[1][i];
		if (A==C) add(Q[0][i][1],1);
		if (A==D) add(Q[1][i][1],1);
		if (A==C&&B==D) add(Q[1][i][2],1);
		if (A==D&&B==C) add(Q[0][i][2],1);
		for (int j=2;j<i&&j*2<k;j++){
			A=rts[j*2+1],B=rts[j*2+2];
			bool from0=check(str_h1,str_h2,k-j+1,k,mp1_h1,mp1_h2,i-j,i-1)&&check(rts_h1,rts_h2,j+1,j+j,mp0_h1,mp0_h2,i-j,i-1);
			bool from1=check(str_h1,str_h2,k-j+1,k,mp0_h1,mp0_h2,i-j,i-1)&&check(rts_h1,rts_h2,j+1,j+j,mp1_h1,mp1_h2,i-j,i-1);
			if (A==C&&from0)
				add(Q[0][i][j*2+1],1);
			if (A==D&&from1)
				add(Q[1][i][j*2+1],1);
			if (A==C&&B==D&&from0)
				add(Q[1][i][j*2+2],1);
			if (A==D&&B==C&&from1)
				add(Q[0][i][j*2+2],1);
		}
		if (i==1) continue;
		for (int j=2;j<=k;j++){
			A=rts[j],B=rts[j-1];
			if (A==C) add(Q[0][i][j],Q[0][i-1][j-1]);
			if (A==D) add(Q[1][i][j],Q[1][i-1][j-1]);
			if (B==C&&A==D) add(Q[1][i][j],Q[0][i-1][j-2]);
			if (B==D&&A==C) add(Q[0][i][j],Q[1][i-1][j-2]);
		}
	}
	for (int i=1;i<=n;i++){
		add(ans,P[0][i][k]);
		add(ans,P[1][i][k]);
		add(ans,Q[0][i][k]);
		add(ans,Q[1][i][k]);
		for (int j=2;i+j<=n&&j*2<k;j++){
			bool from0=check(str_h1,str_h2,k-j-j+1,k-j,mp0_h1,mp0_h2,i+1,i+j)&&check(rts_h1,rts_h2,1,j,mp1_h1,mp1_h2,i+1,i+j);
			bool from1=check(str_h1,str_h2,k-j-j+1,k-j,mp1_h1,mp1_h2,i+1,i+j)&&check(rts_h1,rts_h2,1,j,mp0_h1,mp0_h2,i+1,i+j);
			if (from0) add(ans,P[0][i][k-j*2]);
			if (from1) add(ans,P[1][i][k-j*2]);
		}
		for (int j=2;i+j<=n&&j*2<k;j++){
			bool from0=check(rts_h1,rts_h2,k-j-j+1,k-j,mp0_h1,mp0_h2,i+1,i+j)&&check(str_h1,str_h2,1,j,mp1_h1,mp1_h2,i+1,i+j);
			bool from1=check(rts_h1,rts_h2,k-j-j+1,k-j,mp1_h1,mp1_h2,i+1,i+j)&&check(str_h1,str_h2,1,j,mp0_h1,mp0_h2,i+1,i+j);
			if (from0) add(ans,Q[0][i][k-j*2]);
			if (from1) add(ans,Q[1][i][k-j*2]);
		}
	}
	//printf("ans' %d\n",ans);
	if (k%2==0){
		int t=k>>1;
		for (int i=k>>1;i<=n;i++){
			bool from0=check(rts_h1,rts_h2,k-t+1,k,mp0_h1,mp0_h2,i-t+1,i)&&check(str_h1,str_h2,k-t+1,k,mp1_h1,mp1_h2,i-t+1,i);
			bool from1=check(rts_h1,rts_h2,k-t+1,k,mp1_h1,mp1_h2,i-t+1,i)&&check(str_h1,str_h2,k-t+1,k,mp0_h1,mp0_h2,i-t+1,i);
			add(ans,from0); add(ans,from1);
		}
		for (int i=n-(k>>1)+1;i>0;i--){
			bool from0=check(str_h1,str_h2,1,t,mp0_h1,mp0_h2,i,i+t-1)&&check(rts_h1,rts_h2,1,t,mp1_h1,mp1_h2,i,i+t-1);
			bool from1=check(str_h1,str_h2,1,t,mp1_h1,mp1_h2,i,i+t-1)&&check(rts_h1,rts_h2,1,t,mp0_h1,mp0_h2,i,i+t-1);
			add(ans,from0); add(ans,from1);
		}
		for (int i=1;i<=n;i++){
			for (int j=2;j*2+4<=k;j++){
				if (!(j<=i&&t-j<=n-i)) continue;
				int u=j,v=t-j;
				bool from0=check(rts_h1,rts_h2,k-u+1,k,mp1_h1,mp1_h2,i-u+1,i)&&check(str_h1,str_h2,u+1,u+u,mp0_h1,mp0_h2,i-u+1,i);
				bool to0=check(str_h1,str_h2,u+u+1,u+u+v,mp0_h1,mp0_h2,i+1,i+v)&&check(rts_h1,rts_h2,1,v,mp1_h1,mp1_h2,i+1,i+v);
				bool from1=check(rts_h1,rts_h2,k-u+1,k,mp0_h1,mp0_h2,i-u+1,i)&&check(str_h1,str_h2,u+1,u+u,mp1_h1,mp1_h2,i-u+1,i);
				bool to1=check(str_h1,str_h2,u+u+1,u+u+v,mp1_h1,mp1_h2,i+1,i+v)&&check(rts_h1,rts_h2,1,v,mp0_h1,mp0_h2,i+1,i+v);
				add(ans,from0&&to0); add(ans,from1&&to1);
				//printf("%d: %d + %d:  %d %d  %d %d\n",i,u,v,from0,to0,from1,to1);
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=2;j*2+4<=k;j++){
				if (!(j<=i&&t-j<=n-i)) continue;
				int u=j,v=t-j;
				bool from0=check(str_h1,str_h2,k-u+1,k,mp1_h1,mp1_h2,i-u+1,i)&&check(rts_h1,rts_h2,u+1,u+u,mp0_h1,mp0_h2,i-u+1,i);
				bool to0=check(rts_h1,rts_h2,u+u+1,u+u+v,mp0_h1,mp0_h2,i+1,i+v)&&check(str_h1,str_h2,1,v,mp1_h1,mp1_h2,i+1,i+v);
				bool from1=check(str_h1,str_h2,k-u+1,k,mp0_h1,mp0_h2,i-u+1,i)&&check(rts_h1,rts_h2,u+1,u+u,mp1_h1,mp1_h2,i-u+1,i);
				bool to1=check(rts_h1,rts_h2,u+u+1,u+u+v,mp1_h1,mp1_h2,i+1,i+v)&&check(str_h1,str_h2,1,v,mp0_h1,mp0_h2,i+1,i+v);
				add(ans,from0&&to0); add(ans,from1&&to1);
				//printf("%d: %d + %d:  %d %d  %d %d\n",i,u,v,from0,to0,from1,to1);
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}