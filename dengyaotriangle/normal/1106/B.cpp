#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=100005;

struct f{
	int c,i;
};

bool cmp(f a,f b){
	if(a.c==b.c) return a.i<b.i;
	return a.c<b.c;
}
int n,m;
int r[maxn],c[maxn];
f sr[maxn];
int cp=1;
long long sum=0;

signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		sum+=r[i];
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		sr[i].i=i;sr[i].c=c[i];
	}
	sort(sr+1,sr+1+n,cmp);
	for(int i=1;i<=m;i++){
		int t,d;
		cin>>t>>d;
		if(r[t]>=d){
			r[t]-=d;
			sum-=d;
			cout<<(long long)(c[t])*d<<endl;
		}else{
			long long cur=r[t]*c[t];
			int lft=d-r[t];
			sum-=r[t];
			r[t]=0;
			while(lft!=0){
				bool nok=0;
				if(sum==0){
					cur=0;
					break;
				}
				while(r[sr[cp].i ]==0){
					if(cp>=n){
						nok=1;
						break;
					}
					cp++;
				}
				if(nok){
					cur=0;
					break;
				}
				if(r[sr[cp].i ]>=lft){
					cur+=(long long)(lft)*c[sr[cp].i ];
					sum-=lft;
					r[sr[cp].i ]-=lft;
					lft=0;
				}else{
					cur+=(long long)(r[sr[cp].i ])*c[sr[cp].i ];
					lft-=r[sr[cp].i ];
					sum-=r[sr[cp].i ];
					r[sr[cp].i ]=0;
				}
			}
			cout<<cur<<endl;
		}
	}
	return 0;
}