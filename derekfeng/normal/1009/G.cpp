#include<bits/stdc++.h>
using namespace std;
int num[64],cnt[6];
char c[100004],buf[7];
int pos[100004],got[64];
char ans[100004];
bool check(){
	for(int i=0;i<64;i++)
		if(got[i]>num[i])return 0;
	return 1;
}
int main(){
	scanf("%s",c);int n=strlen(c);
	for(int i=0;i<n;i++)cnt[c[i]-'a']++,pos[i]=63;
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int p;scanf("%d%s",&p,buf);
		int nn=strlen(buf);
		pos[p-1]=0;
		for(int j=0;j<nn;j++)pos[p-1]|=(1<<(buf[j]-'a'));
	}
	for(int i=0;i<64;i++)
		for(int j=0;j<6;j++)if((1<<j)&i)got[i]+=cnt[j];
	for(int i=0;i<n;i++)
		for(int j=0;j<64;j++)if(j&pos[i])num[j]++;
	if(!check()){
		puts("Impossible");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<64;j++)if(j&pos[i])num[j]--;
		for(int j=0;j<6;j++)if(cnt[j]>0&&((1<<j)&pos[i])){
			cnt[j]--;
			for(int k=0;k<64;k++)if((1ll<<j)&k)got[k]--;
			if(check()){
				ans[i]=j;
				break;
			}
			cnt[j]++; 
			for(int k=0;k<64;k++)if((1ll<<j)&k)got[k]++;
		}
	}
	for(int i=0;i<n;i++)putchar(ans[i]+'a');
}