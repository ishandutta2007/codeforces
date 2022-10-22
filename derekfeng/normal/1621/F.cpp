#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c;
ll ans;
char s[100004];
void calc(int t,vector<int>B,int P,int oth,int num0,int num1){
	ll tmp=0;
	for(;;){
		if(t==0){
			if(num1>0)num1--,tmp+=b,ans=max(ans,tmp);
			else return;
		}else{
			if(num1==0){
				if(oth>0||B.size()>0)ans=max(ans,tmp+a);
				if(num0>0)num0--,tmp-=c,ans=max(ans,tmp),num1++;
				else return;
			}else if(B.size()>0){
				int u=B.back();B.pop_back();
				u--,tmp+=a,ans=max(ans,tmp);
				if(u==1)num0++;
				else B.push_back(u);
			}else if(oth>0)oth--,tmp+=a,ans=max(ans,tmp);
			else if(num0>0)num0--,tmp-=c,ans=max(ans,tmp),num1++;
			else if(P>0)P--,tmp-=c,ans=max(ans,tmp);
			else return;
		}
		t^=1;
	}
}
void sol(){
	scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
	if(n==1){puts("0");return;}
	int fi=n+1,ed=0;
	for(int i=1;i<=n;i++)if(s[i]=='1')fi=min(fi,i),ed=max(ed,i);
	if(ed==0){printf("%d\n",a);return;}
	int P=0,oth=0,num0=0,num1=0;
	vector<int>B;
	if(fi!=1)P++,oth+=fi-2;
	if(ed!=n)P++,oth+=n-1-ed;
	for(int i=fi;i<=ed;i++)if(i>1&&s[i]=='1'&&s[i]==s[i-1])num1++;
	for(int i=fi,j;i<=ed;i=j){
		if(s[i]=='1'){j=i+1;continue;}
		int len=0;
		for(j=i;s[j]=='0'&&j<=ed;j++,len++);
		if(len==1)num0++;
		else B.push_back(len);
	}
	sort(B.begin(),B.end(),greater<int>());
	ans=0;
	calc(0,B,P,oth,num0,num1);
	calc(1,B,P,oth,num0,num1);
	printf("%lld\n",ans);
}
int main(){
	int T;scanf("%d",&T);
	while(T--)sol();
}