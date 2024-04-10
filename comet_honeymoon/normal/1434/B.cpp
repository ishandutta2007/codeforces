#include<bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int stk[100005],len;
int tag[100005],idx;
bool flg[100005];
int cnt[100005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=2*N;i++){
		char c=getchar();while(c!='-'&&c!='+') c=getchar();
		if(c=='+') stk[++len]=++idx;
		else{
			int x;scanf("%d",&x);
			if(!len||flg[x]){printf("NO");return 0;}
			flg[x]=1;
			if(tag[stk[len]]>x){printf("NO");return 0;}
			tag[stk[len]]=x;len--;tag[stk[len]]=max(tag[stk[len]],tag[stk[len+1]]);
		}
	}
	for(int i=1;i<=N;i++) cnt[tag[i]]++;
	for(int i=N;i>0;i--){cnt[i]+=cnt[i+1];if(cnt[i]>N-i+1) {printf("NO");return 0;}} 
	printf("YES\n");
	for(int i=1;i<=N;i++) printf("%d ",tag[i]);
}