#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

const int MAXT=10000001;
int nprime=0;
int prime[MAXT-1];
int prcnt[MAXT];
int sp[MAXT];
bool vis[MAXT];
int euler[MAXT];

int gcd(int a,int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

void setprime(int top) {
	sp[1]=1;
    euler[1]=1;
	for(int i=2;i<=top;i++) {
		if(!vis[i]) {
            prcnt[i]++;
			prime[nprime++]=i;
			sp[i]=i;
            euler[i]=i-1;
		}
		for(int j=0;j<nprime && prime[j]*i<=top;j++) {
			vis[prime[j]*i]=1;
            prcnt[prime[j]]++;
			sp[prime[j]*i]=prime[j];
			if(i%prime[j]==0) {
                euler[prime[j]*i] = euler[i] * prime[j];
                break;
            }
            euler[i*prime[j]] =euler[i]*(prime[j]-1);
		}
	}
}

int prsequence(int l,int r) {
    if(r<l) return 0;
    if(l==0) return prcnt[r];
    else return prcnt[r]-prcnt[l-1];
}

int n;

signed main() {
	//freopen("Venus.in","r",stdin);
	//freopen("Venus.out","w",stdout);
	//cout<<"Start."<<endl;
	
	scanf("%lld",&n);
    //cout<<"Read."<<endl;

    setprime(n);
	
	int ans=(n-1)*(n-2)/2;
    for(int i=1;i<=n;i++) {
        //printf("Euler(%lld) = %lld\n",i,euler[i]);
        ans+=(euler[i]-1);
    }

    for(int i=1;i<=n;i++) {
        //printf("Cnt(%lld) = %lld\n",i,prcnt[i]);
        prcnt[i]+=prcnt[i-1];
    }

    for(int i=0;i<nprime;i++) {
        int cnt=prsequence(prime[i],prime[i]);
        ans+=cnt*prsequence(max(prime[i]+1,n/prime[i]+1),max(prime[i]+1,n/2+1)-1);
        ans-=cnt*2*prsequence(max(prime[i]+1,n/2+1),n);
    }
    //cout<<"Calc."<<endl;

    printf("%lld\n",ans);
}