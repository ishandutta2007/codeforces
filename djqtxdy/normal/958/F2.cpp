/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=200005;
int n,m,ans=INF,now,sum;
int a[maxn],b[maxn],cnt[maxn];

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]),a[i]--;
	rep(i,m)scanf("%d",&b[i]),sum+=b[i],now+=(b[i]==0);
	int r=-1;
	rep(i,n){
		while(r<n-1&&now!=m){
			r++;
			cnt[a[r]]++;
			if(cnt[a[r]]==b[a[r]])now++;
		}
		if(now==m)ans=min(ans,r-i+1-sum);
		cnt[a[i]]--;
		if(cnt[a[i]]==b[a[i]]-1)now--;	
	}
	printf("%d",ans==INF?-1:ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/