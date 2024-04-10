#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
int n,m;
const int maxn=55;
typedef pair<pin,pin> info;
info a[maxn];
int id[maxn][maxn];
inline bool cmp(info a,info b){
	return a.w2<b.w2;
}
vector<info> ans;
map<vector<vector<int> >,vector<info> >zb;
vector<vector<int> >que[1005];
inline void push(pin a,pin b){
	// fprintf(stdout, "Move from %d %d to %d %d\n",a.w1,a.w2,b.w1,b.w2);
	if(id[b.w1][b.w2]!=0){
		cerr<<b.w1<<' '<<b.w2<<endl;
	}
	assert(id[b.w1][b.w2]==0);
	if(id[a.w1][a.w2]==0){
		cerr<<a.w1<<' '<<a.w2<<endl;
	}
	assert(id[a.w1][a.w2]!=0);
	assert(abs(a.w1-b.w1)+abs(a.w2-b.w2)==1);
	id[b.w1][b.w2]=id[a.w1][a.w2];
	id[a.w1][a.w2]=0;
	ans.pb(mk(a,b));
}
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int main(){
	read(n);read(m);
	rep(i,1,m){
		read(a[i].w1.w1),read(a[i].w1.w2);
	}
	rep(i,1,m){
		read(a[i].w2.w1),read(a[i].w2.w2);
	}
	sort(a+1,a+1+m,cmp);
	rep(i,1,m){
		id[a[i].w1.w1][a[i].w1.w2]=i;
	}
	if(n==1){
		puts("0");
		return 0;
	}
	if(n==2){
		vector<vector<int> >res;
		vector<int> v1;vector<info> v2;
		v1.pb(0);v1.pb(0);v1.pb(0);
		res.pb(v1);
		v1[1]=id[1][1];v1[2]=id[1][2];
		res.pb(v1);
		v1[1]=id[2][1];v1[2]=id[2][2];
		res.pb(v1);
		zb[res]=v2;int front=0,finish=0;
		que[++finish]=res;
		while(front!=finish){
			vector<vector<int> >tmp=que[++front];
			// rep(i,1,2){
				// rep(j,1,2)printf("%d ",tmp[i][j]);
				// puts("");
			// }puts("");
			std::vector<info> curans=zb[tmp];
			rep(i,1,2)rep(j,1,2)if(tmp[i][j]){
				rep(x,0,3){
					int sti=i+dx[x],stj=j+dy[x];
					if(sti<1||sti>2||stj<1||stj>2)continue;
					if(tmp[sti][stj])continue;
					vector<vector<int> >noone=tmp;

					swap(noone[i][j],noone[sti][stj]);
					if(!zb.count(noone)){
						std::vector<info> nans=curans;
						nans.pb(mk(mk(i,j),mk(sti,stj)));
						zb[noone]=nans;
						que[++finish]=noone;
					}
				}
			}
		}res.clear();v1.clear();
		cerr<<finish<<endl;
		memset(id,0,sizeof(id));
		rep(i,1,m){
			id[a[i].w2.w1][a[i].w2.w2]=i;
		}
		v1.pb(0);v1.pb(0);v1.pb(0);
		res.pb(v1);
		v1[1]=id[1][1];v1[2]=id[1][2];
		res.pb(v1);
		v1[1]=id[2][1];v1[2]=id[2][2];
		res.pb(v1);
		ans=zb[res];
		cout<<ans.size()<<endl;
		for(u32 i=0;i<ans.size();i++){
			printf("%d %d %d %d\n",ans[i].w1.w1,ans[i].w1.w2,ans[i].w2.w1,ans[i].w2.w2);
		}
		return 0;
	}
	int ed=n;
	per(i,n,1){
		if(id[3][i]){
			int j=i;
			while(j+1<=ed){
				push(mk(3,j),mk(3,j+1));
				j++;
			}
			ed--;
		}
	}
	int st=1;
	rep(i,1,n){
		if(id[2][i]){
			int j=i;
			while(j-1>=st){
				push(mk(2,j),mk(2,j-1));
				j--;
			}
			push(mk(2,j),mk(3,j));
			st++;
		}
	}
	cerr<<"!\n";

	cerr<<"!\n";
	rep(i,1,n){
		if(id[1][i]){
			push(mk(1,i),mk(2,i));
			int j=i;
			while(j-1>=st){
				push(mk(2,j),mk(2,j-1));
				j--;
			}
			while(j+1<=st){
				push(mk(2,j),mk(2,j+1));
				j++;
			}
			push(mk(2,j),mk(3,j));
			st++;
		}
	}cerr<<"!\n";
	rep(i,1,n)rep(j,1,n)if(id[i][j]){
		int edi=2,edj=id[i][j];
		int curi=i,curj=j;
		// cerr<<id[2][1]<<endl;
		while(curi>edi){
			push(mk(curi,curj),mk(curi-1,curj));
			curi--;
		}
		while(curj>edj){
			push(mk(curi,curj),mk(curi,curj-1));
			curj--;
		}
		while(curj<edj){
			push(mk(curi,curj),mk(curi,curj+1));
			curj++;
		}
		edi=1;
		while(curi>edi){
			push(mk(curi,curj),mk(curi-1,curj));
			curi--;
		}
	}cerr<<"!\n";
	per(r,m,1){
		int l=r;
		while(a[l-1].w2.w1==a[l].w2.w1)l--;
		rep(x,l,r){
			cerr<<x<<endl;
			int curi=1,curj=x,edi=a[x].w2.w1;
			while(curi<edi){
				push(mk(curi,curj),mk(curi+1,curj));
				curi++;
			}
		}cerr<<"\n";
		int newr=l;
		int curl=l,curr=r;
		while(curl<=curr){
			if(a[curl].w2.w2<=curl){
				int curi=a[curl].w2.w1,curj=curl;
				int edj=a[curl].w2.w2;
				while(curj>edj){
					push(mk(curi,curj),mk(curi,curj-1));
					curj--;
				}
				curl++;
			}else{
				int curi=a[curr].w2.w1,curj=curr;
				int edj=a[curr].w2.w2;
				while(curj<edj){
					push(mk(curi,curj),mk(curi,curj+1));
					curj++;;
				}
				curr--;
			}
		}
		r=newr;
	}cerr<<"!\n";
	rep(i,1,m){
		assert(id[a[i].w2.w1][a[i].w2.w2]==i);
	}cout<<ans.size()<<endl;
	for(u32 i=0;i<ans.size();i++){
		printf("%d %d %d %d\n",ans[i].w1.w1,ans[i].w1.w2,ans[i].w2.w1,ans[i].w2.w2);
	}
	return 0;
}