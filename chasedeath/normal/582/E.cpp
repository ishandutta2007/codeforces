#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)


bool be;

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=510,P=1e9+7;

int A;
int n,a[20][5];
char s[N];


ll sum1[1<<16],sum2[1<<16];
struct Node{
	ll dp[1<<16];
	void init(){ memset(dp,0,sizeof dp); }
	void Rev(){
		rep(i,0,A) {
			if((A^i)<i) continue;
			swap(dp[i],dp[A^i]);
		}
	}
	void operator = (const char x){
		init();
		if(x=='?') {
			rep(i,0,3) {
				int t=0;
				rep(j,0,n-1) if(a[j][i]) t|=1<<j;
				dp[t]++;
				dp[A^t]++;
			}
		} else {
			if(x>='a' && x<='d') {
				int t=x-'a',s=0;
				rep(i,0,n-1) if(!a[i][t]) s|=1<<i;
				dp[s]++;
			} else {
				int t=x-'A',s=0;
				rep(i,0,n-1) if(a[i][t]) s|=1<<i;
				dp[s]++;
			}
		}
		//cout<<"Init char x="<< x<<endl;
		//rep(i,0,A) cout<<i<<' '<<dp[i]<<endl;
	}

	Node operator | (const Node x){
		memcpy(sum1,dp,sizeof dp);
		memcpy(sum2,x.dp,sizeof x.dp);
		rep(i,0,n-1) {
			rep(j,0,A) {
				if(j&(1<<i)) {
					(sum1[j]+=sum1[j^(1<<i)])%=P;
					(sum2[j]+=sum2[j^(1<<i)])%=P;
				}
			}
		}
		//puts("!");
		//rep(i,0,A) cout<<i<<' '<<sum1[i]<<' '<<sum2[i]<<endl;
		//puts("");
		Node res; res.init();
		rep(i,0,A) res.dp[i]=sum1[i]*sum2[i]%P;
		memcpy(sum1,res.dp,sizeof res.dp);
		rep(i,0,n-1) {
			rep(j,0,A) {
				if(j&(1<<i)) {
					(sum1[j]-=sum1[j^(1<<i)])%=P;
				}
			}
		}
		rep(i,0,A) res.dp[i]=(sum1[i]+P)%P;
		//(2*res.dp[i]-sum1[i]+P)%P;
		return res;
	}

	Node operator & (const Node x){
		Rev();
		Node t=x; t.Rev();
		memcpy(sum1,dp,sizeof dp);
		memcpy(sum2,t.dp,sizeof t.dp);
		rep(i,0,n-1) {
			rep(j,0,A) {
				if(j&(1<<i)) {
					(sum1[j]+=sum1[j^(1<<i)])%=P;
					(sum2[j]+=sum2[j^(1<<i)])%=P;
				}
			}
		}
		Node res; res.init();
		rep(i,0,A) res.dp[i]=sum1[i]*sum2[i]%P;
		memcpy(sum1,res.dp,sizeof res.dp);
		rep(i,0,n-1) {
			rep(j,0,A) {
				if(j&(1<<i)) {
					(sum1[j]-=sum1[j^(1<<i)])%=P;
				}
			}
		}
		rep(i,0,A) res.dp[i]=(sum1[i]+P)%P;
		Rev();
		res.Rev();
		return res;
	}

	Node operator + (const Node x){
		Node res;
		rep(i,0,A) res.dp[i]=(x.dp[i]+dp[i])%P;
		return res;
	}
};

Node valstk[N/2];
int optstk[N],top1,top2;

void Del(){
	if(optstk[top2]=='|') valstk[top1-1]=valstk[top1-1]|valstk[top1];
	if(optstk[top2]=='&') valstk[top1-1]=valstk[top1-1]&valstk[top1];
	if(optstk[top2]=='?') {
		//puts("Dying ");
		//Node t=(valstk[top1-1]|valstk[top1]);
		//rep(i,0,A) cout<<i<<' '<<valstk[top1-1].dp[i]<<' '<<valstk[top1].dp[i]<<' '<<t.dp[i]<<endl;
		//puts("");
		valstk[top1-1]=(valstk[top1-1]&valstk[top1])+(valstk[top1-1]|valstk[top1]);
	}
	top1--,top2--;
}


Node Solve(){
	int opt=0;
	rep(i,1,strlen(s+1)) {
		if(s[i]=='(') optstk[++top2]=s[i];
		else if(s[i]==')') {
			while(top2 && optstk[top2]!='(') Del();
			top2--;
		} else {
			opt^=1;
			if(opt) {
				top1++;
				valstk[top1]=s[i];
			} else {
				optstk[++top2]=s[i];
			}
		}
	}
	while(top2) Del();
	return valstk[1];
}


bool ed;

int main(){
	//n=3,A=7;
	//Node a,b;a.init(),b.init();
	//a.dp[0]=a.dp[1]=1,b.dp[2]=1,b.dp[3]=1,b.dp[7]=1;
	//Node t=a&b;
	//rep(i,0,A) cout<<i<<' '<<t.dp[i]<<endl;

	//cout<<(&ed-&be)<<endl;
	scanf("%s",s+1);
	n=rd();
	int S=0;
	rep(i,0,n-1) {
		rep(j,0,4) a[i][j]=rd();
		S|=a[i][4]<<i;
	}
	A=(1<<n)-1;
	Node t=Solve();
	//rep(i,0,A) cout<<i<<' '<<t.dp[i]<<endl;
	printf("%lld\n",t.dp[S]);
}