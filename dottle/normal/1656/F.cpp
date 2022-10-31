#pragma GCC optimize("Ofast","-funroll-loops","-fdelete-null-pointer-checks")
#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")
#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
int fa[N];
int MN[N],id[N];

int gf(int k){
	return k==fa[k]?k:fa[k]=gf(fa[k]);
} 
bool mrg(int x,int y){
	int fx=gf(x),fy=gf(y);
	if(fx==fy)return 0;
	fa[fx]=fy;return 1;
}

int calc(int t){
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=n,res=0;
	while(cnt>1){
		int mn=a[1],mnid=gf(1),sc,scid;
		for(int i=1;i<=n;i++)MN[i]=1e18;
		for(int i=2;i<=n;i++){
			if(gf(1)!=gf(i)){
				scid=gf(i);
				sc=a[i];
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if((t+a[i])<0)break;
			int T=gf(i);
			if(T==mnid){
				int w=a[i]*sc+t*(a[i]+sc);
				if(w<MN[T]){
					MN[T]=w;
					id[T]=scid;
				}
			}else{
				int w=a[i]*mn+t*(a[i]+mn);
				if(w<MN[T]){
					MN[T]=w;
					id[T]=mnid;
				}
			}
		}
		mn=a[n],mnid=gf(n);
		for(int i=n-1;i>=1;i--){
			if(gf(n)!=gf(i)){
				scid=gf(i);
				sc=a[i];
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if((t+a[i])>0)break;
			int T=gf(i);
			if(T==mnid){
				int w=a[i]*sc+t*(a[i]+sc);
				if(w<MN[T]){
					MN[T]=w;
					id[T]=scid;
				}
			}else{
				int w=a[i]*mn+t*(a[i]+mn);
				if(w<MN[T]){
					MN[T]=w;
					id[T]=mnid;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(MN[i]!=1e18){
				int fl=mrg(i,id[i]);
				cnt-=fl;
				res+=fl*MN[i];
			}
		}
	}
	return res;
}

void solve(){
	cin>>n;
	int s=0,mx=-1e9,mn=1e9;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i],mn=min(mn,a[i]),mx=max(mx,a[i]);
	if(s+mn*(n-2)>0||s+mx*(n-2)<0){cout<<"INF"<<endl;return;}
	sort(a+1,a+1+n);
	int l=-1e9,r=1e9,res=r;
	while(l<=r){
		int mid=((l+r)>>1);
		int A=calc(mid);
		int B=calc(mid+1);
		if(A>B)res=A,r=mid-1;
		else l=mid+1;
	}
	cout<<max(calc(l),calc(r))<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}