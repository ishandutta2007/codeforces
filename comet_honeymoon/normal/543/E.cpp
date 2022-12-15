#include<bits/stdc++.h>
using namespace std;

const int maxN=200005,LEN=450;
int N,M,Q,len,cntb; //len cntb  
int bg[LEN],ed[LEN]; //bg ed  
int inb[maxN]; //inb  
int A[maxN],id[maxN];
bool cmp(int a,int b){
	return A[a]>A[b];
}
int Lpos[maxN],Rpos[maxN]; // 
int Linb[maxN],Rinb[maxN]; // 
int Lans[maxN],Rans[maxN]; // 

int ans[LEN],val[maxN],lzy[LEN];
int ANS[LEN][LEN],bgval[LEN][LEN];

void init(){
	scanf("%d%d",&N,&M);
//	N=200000,M=200;
	len=sqrt(N);
	for(int i=1;i<=N;i++) inb[i]=(i-1)/len+1,bg[inb[i]]=(bg[inb[i]]?bg[inb[i]]:i),ed[inb[i]]=i;cntb=inb[N];
	
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),id[i]=i;
//	for(int i=1;i<=N;i++) A[i]=i,id[i]=i;
	sort(id+1,id+N+1,cmp);
	
	for(int i=1;i<=N;i++){
		Lpos[i]=max(1,id[i]-M+1),Rpos[i]=id[i];
		Linb[i]=inb[Lpos[i]],Rinb[i]=inb[Rpos[i]];
		if(inb[i]!=inb[i-1]){ //pushdown tag LansRans  tag  tag 
			for(int j=1;j<=N;j++) val[j]+=lzy[inb[j]];
			for(int j=1;j<=cntb;j++)
				ANS[inb[i]][j]=ans[j],bgval[inb[i]][j]=val[bg[j]],lzy[j]=0;
		}
		// 
		if(Linb[i]==Rinb[i]){
			int debug_cnt=0;
			for(int j=Lpos[i];j<=Rpos[i];j++) val[j]++,ans[inb[j]]=max(ans[inb[j]],val[j]+lzy[inb[j]]),debug_cnt++;
			for(int j=bg[Linb[i]];j<=ed[Linb[i]];j++) Lans[i]=max(Lans[i],val[j]),debug_cnt++;
		}
		else{
			for(int j=Lpos[i];j<=ed[Linb[i]];j++) val[j]++,ans[inb[j]]=max(ans[inb[j]],val[j]+lzy[inb[j]]);
			for(int j=Linb[i]+1;j<=Rinb[i]-1;j++) lzy[j]++,ans[j]++;
			for(int j=bg[Rinb[i]];j<=Rpos[i];j++) val[j]++,ans[inb[j]]=max(ans[inb[j]],val[j]+lzy[inb[j]]);
			for(int j=bg[Linb[i]];j<=ed[Linb[i]];j++) Lans[i]=max(Lans[i],val[j]);
			for(int j=bg[Rinb[i]];j<=ed[Rinb[i]];j++) Rans[i]=max(Rans[i],val[j]);
		}
	}
}

int lstans;
int brute_query(int L,int R,int bid,int tmp,int q){
	int ANS=0;
	for(int i=bg[bid];i<L;i++) tmp+=(A[i+M]>=q)-(A[i]>=q);
	for(int i=L;i<=R;i++) ANS=max(ANS,tmp),tmp+=(A[i+M]>=q)-(A[i]>=q);
	return ANS;
}

int main(){
	init();
	scanf("%d",&Q);
	while(Q--){
		int QL,QR,QQ,QX;scanf("%d%d%d",&QL,&QR,&QQ);QQ^=lstans;
		A[N+1]=QQ;QX=upper_bound(id+1,id+N+1,N+1,cmp)-id-1;
		memset(lzy,0,sizeof(lzy));
		for(int i=1;i<=cntb;i++) ans[i]=ANS[inb[QX]][i];
		int bgvalL=bgval[inb[QX]][inb[QL]],bgvalR=bgval[inb[QX]][inb[QR]];
		for(int i=bg[inb[QX]];i<=QX;i++){
			ans[Linb[i]]=Lans[i];
			if(Linb[i]!=Rinb[i]) ans[Rinb[i]]=Rans[i],lzy[Linb[i]+1]++,lzy[Rinb[i]]--; 
			if(Lpos[i]<=bg[inb[QL]]&&bg[inb[QL]]<=Rpos[i]) bgvalL++;
			if(Lpos[i]<=bg[inb[QR]]&&bg[inb[QR]]<=Rpos[i]) bgvalR++;
		}
		for(int i=1;i<=cntb;i++) lzy[i]+=lzy[i-1];
		int ANS=0;
		if(inb[QL]==inb[QR]) ANS=brute_query(QL,QR,inb[QL],bgvalL,QQ);
		else{
			ANS=max(ANS,brute_query(QL,ed[inb[QL]],inb[QL],bgvalL,QQ));
			ANS=max(ANS,brute_query(bg[inb[QR]],QR,inb[QR],bgvalR,QQ));
			for(int i=inb[QL]+1;i<=inb[QR]-1;i++)
				ANS=max(ANS,ans[i]+lzy[i]);
		}
		printf("%d\n",lstans=M-ANS);
	}

	return 0;
}