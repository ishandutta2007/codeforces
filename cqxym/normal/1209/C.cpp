#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
vector<int>Q[10];
int b[200001];
int p[200001];
int ct[10];
void Solve(){
	for(R i=0;i<10;i++){
		Q[i].clear();
		ct[i]=0;
	}
	int n;
	scanf("%d\n",&n);
	char c;
	for(R i=0;i<n;i++){
		b[i]=0;
		c=getchar();
		Q[c-48].push_back(i);
		p[i]=c-48;
		ct[c-48]++;
	}
	int l=-1;
	for(R i=0;i<10;i++){
		if(ct[i]==0){
			continue;
		}
		int u=Q[i].size();
		bool f=false;
		for(R j=upper_bound(Q[i].begin(),Q[i].end(),l)-Q[i].begin();j<u;j++){
			int o=Q[i][j];
			if(o>l){
				ct[p[o]]--;
				l=o;
				b[o]=1;
			}else{
				f=true;
				break;
			}
		}
		if(f==true||ct[i]>0){
			break;
		}
	}
	l=-1;
	for(R i=0;i<n;i++){
		if(b[i]==0){
			if(p[i]>=l){
				l=p[i];
			}else{
				puts("-");
				return;
			}
			b[i]=2;
		}
	}
	for(R i=0;i<n;i++){
		printf("%d",b[i]);
	}
	puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}