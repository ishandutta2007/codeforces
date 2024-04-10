#include<bits/stdc++.h>
using namespace std;
int n,a[200004],cnt;
char s[200004];
vector<int>vl,vr;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(i==1||s[i]!=s[i-1])cnt++;
	sort(a+1,a+n+1);
	for(int i=n-cnt+1;i<=n;i++)vr.push_back(a[i]);
	for(int i=n-cnt;i;i--)vl.push_back(a[i]);
	for(int i=0;i<vl.size();i++){
		if(i&1){
			if(s[1]=='R')vl[i]=-vl[i];
		}else{
			if(s[1]=='L')vl[i]=-vl[i];
		}
	}
	int cr=0,cl=0;
	for(int i=1;i<=n;i++){
		if(i==1||s[i]!=s[i-1])printf("%d %c\n",abs(vr[cr++]),s[i]);
		else{
			if(vl[cl]>0)printf("%d L\n",vl[cl++]);
			else printf("%d R\n",-vl[cl++]);
		}
	}
}