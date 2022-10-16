#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
ll T,n,a[MAXN];
ll pre1[MAXN],next1[MAXN],pre2[MAXN],next2[MAXN],ret;
vector<int>ans;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
void Delete(int i){
	int p=pre1[i],n=next1[i];
	pre1[i]=next1[i]=0;
	next1[p]=n;
	pre1[n]=p; 
}
void Delete2(int i){
	int p=pre2[i],n=next2[i];
	pre2[i]=next2[i]=0;
	next2[p]=n;
	pre2[n]=p;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;ret=0;ans.clear();
		rep(i,1,n){
			cin>>a[i];
			next1[i]=i+1;
			pre1[i]=i-1;
			pre2[i]=next2[i]=0;
		}
		pre1[1]=n;next1[n]=1;
		int last=0,head=0;
		rep(i,1,n){
			if(gcd(a[i],a[next1[i]])==1){
				if(!last){
					head=i;
				}else{
					pre2[i]=last;
					next2[last]=i;
				}
				last=i;
			}
		}
		pre2[head]=last;
		next2[last]=head;
		if(!head){
			printf("0\n");continue; // 
		}
		int tmp=head;
		while(tmp){
			//next1[tmp] 
		//	printf("%d %d\n",tmp,next1[tmp]);
			ret++,ans.pb(next1[tmp]);
			if(next1[tmp]==tmp)break;
			if(next2[tmp]==next1[tmp]){Delete2(next2[tmp]);}
			Delete(next1[tmp]);
		//	printf("TMP:%d\n",next2[tmp]);
			if(next2[tmp]){
				if(gcd(a[tmp],a[next1[tmp]])!=1){
					//tmp 
					ll t=next2[tmp];
					Delete2(tmp);
					if(tmp==t)break;
					tmp=t;
				}else{
					// 
					tmp=(next2[tmp])?next2[tmp]:tmp;
				}
			}else break;
		}
		cout<<ret<<' ';
		for(vit it=ans.begin();it!=ans.end();it++){
			cout<<*it<<' ';
		}
		cout<<'\n';
	}
	return 0;
}