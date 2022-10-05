#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int ans[30];

int main(){
	int Q,a,n;
	cin>>Q;
	rep(i,2,25){
		int x=(1<<i)-1;
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				ans[i]=x/j;
				break;
			}
		if(!ans[i])ans[i]=1;
	}
	while(Q--){
		cin>>a;
		int x=a;n=0;
		while(x){
			x>>=1;
			n++;
		}
		if(a==(1<<n)-1)printf("%d\n",ans[n]);
		else printf("%d\n",(1<<n)-1);
	}

	return 0;
}