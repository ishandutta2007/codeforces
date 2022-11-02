#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#define maxn 1000009
using namespace std;
char s[maxn];
int lu[maxn],ld[maxn],ru[maxn],rd[maxn],n;
int rk[maxn];
int uu[maxn],dd[maxn];
int cot[maxn];
long long sumu[maxn],sumd[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='D'){
			ld[i]=ld[i-1]+1;
			lu[i]=lu[i-1];
		}
		else{
			lu[i]=lu[i-1]+1;
			ld[i]=ld[i-1];
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='D'){
			rd[i]=rd[i+1]+1;
			ru[i]=ru[i+1];
		}
		else{
			ru[i]=ru[i+1]+1;
			rd[i]=rd[i+1];
		}
	}
	int U=0,D=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='U'){
			rk[i]=U+1;
			U++;
			uu[U]=i;
			sumu[U]=sumu[U-1]+i;
			cot[i]=D;
		}
		else{
			rk[i]=D+1;
			D++;
			dd[D]=i;
			sumd[D]=sumd[D-1]+i;
			cot[i]=U;
		}

	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='D'){
			if(rd[i+1]>=lu[i-1]){
				ans=2*(sumd[rk[i]+cot[i]]-sumd[rk[i]])-sumu[cot[i]]*2+i;
			}
			else{
				ans=2*(sumd[D]-sumd[rk[i]])-2*(sumu[cot[i]]-sumu[cot[i]-rd[i]])+n+1+i;
			}
		}
		else{
			if(rd[i+1]>lu[i-1]){
				ans=2*(sumd[cot[i]+lu[i]]-sumd[cot[i]])-2*sumu[rk[i]-1]-i;
			}
			else{
				ans=2*(sumd[D]-sumd[cot[i]])-2*(sumu[rk[i]-1]-sumu[rk[i]-1-(D-cot[i])])+n+1-i;
			}
		}
		cout<<ans<<" ";
	}
	
	return 0;
}