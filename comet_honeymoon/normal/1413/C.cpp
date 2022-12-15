#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int A[6];
struct node{
	int v,p;
	bool operator <(const node b)const{return v<b.v;}
}B[600005];int idx;
int cnt[100005],tot;
void inc(int x){if(!cnt[x]++) tot++;}
void dec(int x){if(!--cnt[x]) tot--;}

int main(){
	for(int i=0;i<6;i++) scanf("%d",&A[i]);
	sort(A,A+6);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		int bi;scanf("%d",&bi);
		for(int j=0;j<6;j++) B[++idx]=(node){bi-A[j],i};
	}
	sort(B+1,B+6*N+1);
	int ans=1e9;
	int l=1,r=1;inc(B[1].p);while(tot!=N) inc(B[++r].p);ans=min(ans,B[r].v-B[l].v);
	while(1){
		dec(B[l++].p);
		while(r<=6*N&&tot!=N) inc(B[++r].p);
		if(r>6*N) break;
		ans=min(ans,B[r].v-B[l].v);
	}
	printf("%d\n",ans);
}