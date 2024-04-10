// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=66000;
int n,a,b,c,d,e,f,ans[N];

// ----------  ---------- //

struct CartesianTree{
	struct node{
		int id,v,fa,ls,rs;
	}tr[N];
	inline void init(){tr[0].id=tr[0].v=tr[0].ls=tr[0].rs=tr[0].fa=0;}
	inline void insert(int x,int y,int z){
		tr[x].id=x;tr[x].v=y;tr[x].fa=z;tr[x].ls=tr[x].rs=0;
		int k=x-1;
		while(tr[k].v>tr[x].v) k=tr[k].fa;
		tr[x].ls=tr[k].rs;tr[k].rs=x;
		tr[x].fa=k;tr[tr[x].rs].fa=x;
	}
}CT;

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	cout<<"AND 1 2"<<endl;rd(a);
	cout<<"AND 2 3"<<endl;rd(b);
	cout<<"XOR 1 2"<<endl;rd(c);
	cout<<"XOR 2 3"<<endl;rd(d);
	cout<<"OR 1 3"<<endl;rd(e);
	for(re i=1;i<n;i<<=1){
		if(e&i){
			if((c^d)&i){
				if(d&i){
					if(a&i) ans[1]+=i,ans[2]+=i;
					else ans[3]+=i;
				}
				else{
					if(b&i) ans[2]+=i,ans[3]+=i;
					else ans[1]+=i;
				}
			}
			else ans[1]+=i,ans[3]+=i,!(c&i)?ans[2]+=i:1;
		}
		else{
			if(c&i) ans[2]+=i;
		}
	}
	for(re i=4;i<=n;i++){
		cout<<"XOR 1 "<<i<<endl;
		rd(a);
		ans[i]=ans[1]^a;
	}
	cout<<"! ";
	for(re i=1;i<=n;i++) cout<<ans[i]<<' ';cout<<endl;
	return 0;
}

// ---------- Main ---------- //