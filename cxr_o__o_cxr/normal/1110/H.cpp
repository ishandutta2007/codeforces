#include<bits/stdc++.h>
using namespace std;
//#define get(u,k) (ch[u][k]?ch[u][k]:ch[u][k]=++tot)
#define get(u , k) (!ch[u][k] ? ch[u][k] = ++tot : ch[u][k])
#define gmax(x,y) (x<y?x=y:x)
const int N=2004;
char sl[N],sr[N];
int n,lenl,lenr,tot=1,ch[N*10][10],sum[N*10][N],fail[N*10];
inline void build_trie(){
	lenl=strlen(sl+1);lenr=strlen(sr+1);
	int u=1,v=1;
	if(lenl==lenr){
		for(int i=1;i<=lenl;i++){
			if(u==v){
				for(int k=sl[i]-'0'+1;k<sr[i]-'0';k++)
					sum[get(u,k)][lenl-i]++;
			} 
			else{
				for(int k=sl[i]-'0'+1;k<10;k++)
					sum[get(u,k)][lenl-i]++;
				for(int k=sr[i]-'0'-1;k>=0;k--)
					sum[get(v,k)][lenl-i]++;
			}
			u=get(u,sl[i]-'0');
			v=get(v,sr[i]-'0');
		}
		sum[u][0]++;
		if(u!=v)sum[v][0]++;
	}
	else{
		for(int i=1;i<=lenl;i++){
			for(int k=sl[i]-'0'+1;k<10;k++)
				sum[get(u,k)][lenl-i]++;
			u=get(u,sl[i]-'0');
		}
		for(int i=1;i<=lenr;i++){
			for(int k=sr[i]-'0'-1;k>=(i==1);k--)
				sum[get(v,k)][lenr-i]++;
			v=get(v,sr[i]-'0');
		}
		for(int i=lenl+1;i<lenr;i++)
			for(int k=1;k<10;k++)//0 
				sum[get(1,k)][i-1]++;
		sum[u][0]++;sum[v][0]++;
	}
}
queue<int>q;
inline void build_acam(){
	for(int i=0;i<10;i++)ch[0][i]=1;
	q.push(1);
//	for(int i=1;i<=tot;i++)
//		for(int j=0;j<10;j++)
//			if(ch[i][j])printf("%d %d %d\n",i,ch[i][j],j);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<lenr;i++)sum[x][i]+=sum[fail[x]][i];
		for(int i=0;i<10;i++)
			if(!ch[x][i])ch[x][i]=ch[fail[x]][i];
			else{
				fail[ch[x][i]]=ch[fail[x]][i];
				q.push(ch[x][i]);
			}
	} 
	for(int i=1;i<=tot;i++)
		for(int j=1;j<n;j++)
			sum[i][j]+=sum[i][j-1];
//	for(int i=1;i<=tot;i++){
//		for(int j=0;j<n;j++)cout<<sum[i][j]<<" ";
//		puts("");
//	}
}
int ans,f[N][N*10];
bitset<N*10>can[N];
int main(){
	scanf("%s%s%d",sl+1,sr+1,&n);
	build_trie();
	build_acam();
	memset(f,0xcf,sizeof(f));
	f[0][1]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=tot;j++)if(f[i][j]>=0){
			for(int k=0;k<10;k++){
				gmax(f[i+1][ch[j][k]],f[i][j]+sum[ch[j][k]][n-i-1]);
			}
		}
	}
	for(int j=1;j<=tot;j++)
		gmax(ans,f[n][j]);
	cout<<ans<<"\n";
	for(int j=1;j<=tot;j++)
		if(f[n][j]==ans)can[n][j]=1;
	for(int i=n-1;i>=0;i--)
		for(int j=1;j<=tot;j++)if(f[i][j]>=0){
			for(int k=0;k<10;k++){
				if(can[i+1][ch[j][k]]&&(f[i][j]+sum[ch[j][k]][n-i-1]==f[i+1][ch[j][k]])){
					can[i].set(j);
					break;
				}
			}
		}
	int u=1;
	for(int i=1;i<=n;i++)
		for(int k=0;k<10;k++)
			if(can[i][ch[u][k]]&&f[i-1][u]+sum[ch[u][k]][n-i]==f[i][ch[u][k]]){
				putchar(k|48);
				u=ch[u][k];
				break;
			}
	return (0-0);
}