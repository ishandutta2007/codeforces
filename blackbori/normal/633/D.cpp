#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

LL D[1111],K[1111];
int I[1111],I_[1111],S[1111][1111];
int st[1111],sp;

int n,s,ans;

int main()
{
//	freopen("input.txt","r",stdin);
	
	int i,j,l,a,b,c,next;
	LL *k;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%I64d",D+i);
	}
	
	sort(D,D+n);
	
	I[i]=0;
	K[0]=D[0]; I[0]++;
	for(i=1;i<n;i++){
		if(D[i] != D[i-1]) s++;
		K[s]=D[i];
		I[s]++;
	}s++;
	
	for(i=0;i<s;i++){
		for(j=i;j<s;j++){
			k=lower_bound(K,K+s,K[i]+K[j]);
			if(k[0]==K[i]+K[j]) S[i][j]=S[j][i]=(k-K);
			else S[i][j]=S[j][i]=-1;
		}
	}
/*	
	for(i=0;i<s;i++) printf("%I64d ",K[i]);
	printf("\n\n");
	
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			printf("%d ",S[i][j]);
		}
		printf("\n");
	}
	*/
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			a=i,b=j,c=2;
			if(a==b && I[i]<2) continue;
			I[a]--; I[b]--;
			st[1]=a; st[2]=b;
			while(1){
				next = S[a][b];
				if(next == -1 || I[next] <= 0) break;
				I[next]--; st[++c]=next;
				a=b; b=next;
			}
			ans = max(ans,c);
//			printf("%d %d %d\n",i,j,c);
			for(l=1;l<=c;l++) I[st[l]]++;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}