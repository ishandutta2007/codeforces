#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
inline int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}

const int N=1e5+10,P=1e9+7;
const ll P1=19260817,K1=558973;
const ll P2=1e9+13,K2=997453;


int n;
int a[N],b[N];
vector <int> G[N];
ll h1[N],h2[N];
ll po1[N]={1},po2[N]={1};

struct Node{
	int len,p;
	bool operator < (const Node __ )const{
		if(len!=__.len) return len<__.len;
		return p<__.p;
	}
}Q[N*100];
int qc;


int main(){
	rep(i,1,n=rd()) a[i]=b[i]=rd();
	rep(i,1,n) po1[i]=po1[i-1]*K1%P1;
	rep(i,1,n) po2[i]=po2[i-1]*K2%P2;
	sort(b+1,b+n+1);int bc=unique(b+1,b+n+1)-b-1;
	rep(i,1,n) a[i]=lower_bound(b+1,b+bc+1,a[i])-b;
		rep(i,1,bc) G[i].clear();
		rep(i,1,n) G[a[i]].push_back((int)i);
		rep(i,1,n) {
			h1[i]=(h1[i-1]*K1+a[i])%P1;
			h2[i]=(h2[i-1]*K2+a[i])%P2;
		}
		rep(i,1,bc) {
			//if(i==1) {
				//rep(j,0,G[i].size()-1) cout<<G[i][j]<<' ';puts("");
			//}
			rep(j,0,(int)G[i].size()-2) rep(k,j+1,G[i].size()-1) {
				int a=G[i][j],b=G[i][k];
				int l=b-a;
				if(b+l-1>n) continue;
				//cout<<"check"<<a<<' '<<b<<endl;
				if((h1[a+l-1]-h1[a-1]*po1[l]%P1+P1)%P1 == (h1[b+l-1]-h1[b-1]*po1[l]%P1+P1)%P1  &&
					(h2[a+l-1]-h2[a-1]*po2[l]%P2+P2)%P2 == (h2[b+l-1]-h2[b-1]*po2[l]%P2+P2)%P2) 
				 {
					 //cout<<"Update "<<l<<' '<<a<<' '<<b<<endl;
					 Q[++qc]=(Node){l,a};
				}
			}
		}
	sort(Q+1,Q+qc+1);
	int r=1;
	rep(i,1,qc) if(Q[i].p>=r) r=Q[i].p+Q[i].len;
	printf("%d\n",n-r+1);
	rep(i,r,n) printf("%d ",b[a[i]]);
	puts("");
}