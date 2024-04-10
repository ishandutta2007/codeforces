#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,q,s;
map<int,int>mp[1000004];
char buf[10];
int x,y,c;
int a[2];
int p2[1000004];
int R[1000004][2],C[1000004][2];
int getr(int r){
	if(R[r][0]>0&&R[r][1]>0)return 2;
	if(R[r][0]>0||R[r][1]>0)return 0;
	return 1;
}
int getc(int c){
	if(C[c][0]>0&&C[c][1]>0)return 2;
	if(C[c][0]>0||C[c][1]>0)return 0;
	return 1;
}
int rc[3],cc[3];
void del(int x,int y){
	if(mp[x].find(y)==mp[x].end())return;
	rc[getr(x)]--,cc[getc(y)]--;
	int c=mp[x][y];
	mp[x].erase(mp[x].find(y));
	a[(x&1)^(y&1)^c]--;
	R[x][c^(y&1)]--,C[y][c^(x&1)]--;
	rc[getr(x)]++,cc[getc(y)]++;
}
void ins(int x,int y,int c){
	del(x,y);
	rc[getr(x)]--,cc[getc(y)]--;
	mp[x][y]=c;
	a[(x&1)^(y&1)^c]++;
	R[x][c^(y&1)]++,C[y][c^(x&1)]++;
	rc[getr(x)]++,cc[getc(y)]++;
}
void ask(){
	if(a[0]>0&&a[1]>0)s=0;
	else if(a[0]==0&&a[1]==0)s=2;
	else s=1;
	int t1=0,t2=0;
	if(rc[2]==0)t1=p2[rc[1]];
	if(cc[2]==0)t2=p2[cc[1]];
	printf("%d\n",((t1+t2-s)%M+M)%M);
}
int main(){
	p2[0]=1;
	for(int i=1;i<1000004;i++)p2[i]=(p2[i-1]+p2[i-1])%M;
	scanf("%d%d%d",&n,&m,&q);
	rc[1]=n,cc[1]=m;
	while(q--){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		if(t==-1)del(x,y);
		else ins(x,y,t);
		ask();
	}
}