#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define osn j2
using namespace std;
 
typedef long long ll;
typedef double db;
typedef long double ldb;
 
const int inf=1e9;
const int maxn=6e5+10;
 
char _buf_[1<<23],*_st_,*_ed_,_wbuf_[1<<23],*_wed_=_wbuf_;
#define getchar() (_st_==_ed_&&(_ed_=(_st_=_buf_)+fread(_buf_,1,1<<23,stdin),_st_==_ed_)?-1:*_st_++)
#define putchar(x) (*_wed_++=x)
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void read(ll &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void prt(int x){
	x<0&&(putchar('-'),x=~x+1);
	x>9&&(prt(x/10),0);
	putchar(x%10^48);
}
void putchar_final(){fwrite(_wbuf_,1,_wed_-_wbuf_,stdout);}
 
map <int,int> mn[730],mx[730];
map <int,int> ans;
ll add[730],a[maxn];
bool can[730];
int n,q,s,b[730];
 
void update(int t,int pos,ll x){
	if(mn[t].find(x)==mn[t].end()){
		mn[t][x]=pos;
		mx[t][x]=pos;
	}
	else{
		mn[t][x]=min(mn[t][x],pos);
		mx[t][x]=max(mx[t][x],pos);
	}
}
 
int main(){
	read(n); read(q);
	s=int(sqrt(n)); if(s*s<=n) s++;
	for(int i=0;i<n;i++) read(a[i]);
	for(int i=0;i<730;i++) b[i]=inf+1;
	for(int i=0;i<n;i++){
		b[i/s]=min(b[i/s],int(a[i]));
		can[i/s]=1;
		update(i/s,i,a[i]);
	}
	for(int i=0;i<q;i++){
		int f; 
		read(f);
		if(f==1){
			ans.clear();
			int l,r; ll x;
			read(l); read(r); read(x);
			l--;
			if(l/s==r/s){
				if(!can[l/s]) continue;
				mn[l/s].clear(); mx[l/s].clear();
				for(int j=l/s*s;j<(l/s+1)*s;j++){
					a[j]+=add[l/s];
					if(l<=j&&j<r) a[j]+=x;
					if(a[j]<=inf)
						update(l/s,j,a[j]);
				}
			}
			else{
				for(int j=l/s+1;j<r/s;j++){
					if(can[j]) add[j]+=x;
					if(add[j]+b[j]>inf) can[j]=0;
				}
				if(can[l/s]){
					mn[l/s].clear(); mx[l/s].clear();
					bool flag=false;
					for(int j=l/s*s;j<(l/s+1)*s;j++){
						a[j]+=add[l/s];
						if(j>=l) a[j]+=x;
						if(a[j]<=inf){
							update(l/s,j,a[j]);
							flag=true;
						}
					}
					can[l/s]=flag;
					add[l/s]=0;
				}
				if(can[r/s]){
					mn[r/s].clear(); mx[r/s].clear();
					bool flag=false;
					for(int j=r/s*s;j<(r/s+1)*s;j++){
						a[j]+=add[r/s];
						if(j<r) a[j]+=x;
						if(a[j]<=inf){
							flag=true;
							update(r/s,j,a[j]);
						}
					}
					can[r/s]=flag;
					add[r/s]=0;
				}
			}
		}
		else{
			ll y;
			read(y);
			if(ans.find(y)!=ans.end()){
				prt(ans[y]);putchar('\n');
				continue;
			}
			int an=inf,ax=-1;
			for(int i=0;i<n/s+1;i++){
				ll x=y-add[i];
				if(add[i]>inf) continue;
				if(mn[i].find(x)!=mn[i].end()){
					an=min(an,mn[i][x]);
					ax=max(ax,mx[i][x]);
				}	
			}
			if(an==inf){
				ans[y]=-1;
				prt(ans[y]);putchar('\n');
			}
			else{
				ans[y]=ax-an;
				prt(ans[y]);putchar('\n');
			}	
		}
	}
	putchar_final();
	return 0;
}