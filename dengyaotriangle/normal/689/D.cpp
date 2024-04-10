# include <bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn],b[maxn];
int sta[maxn][20],stb[maxn][20];

int ma(int l,int r){
	int cr=log2(r-l+1);
	return max(sta[l][cr],sta[r-(1<<cr)+1][cr]);
}
int mb(int l,int r){
	int cr=log2(r-l+1);
	return min(stb[l][cr],stb[r-(1<<cr)+1][cr]);
}                  
bool chk(int l,int r,bool eql){
	int mia=ma(l,r);                            
	int mib=mb(l,r);
	if(eql) return mia>=mib;
	return mia>mib;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) sta[i][0]=a[i];
	for(int i=1;i<=n;i++) stb[i][0]=b[i];
	for(int i=1;i<20;i++) for(int j=1;j<=n;j++) if(j+(1<<i)-1<=n) sta[j][i]=max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
	for(int i=1;i<20;i++) for(int j=1;j<=n;j++) if(j+(1<<i)-1<=n) stb[j][i]=min(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
	//for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) cout<<i<<j<<ma(i,j)<<mb(i,j)<<endl;
	long long ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(r-l>3){
			int m=(l+r)/2;
			if(chk(i,m,0))r=m;
			else l=m;
		}
		int p1=-1,p2=-1;
		for(int j=l;j<=r;j++){
			if(chk(i,j,0)){
				p1=j-1;
				break;
			}
		}
		if(p1==-1)p1=r;
		l=i;r=n;
		while(r-l>3){
			int m=(l+r)/2;
			if(chk(i,m,1)) r=m;
			else l=m;
		}
		for(int j=r;j>=l;j--){
			if(chk(i,j,1)) if(ma(i,j)==mb(i,j)) p2=j;
		}
		if(p2!=-1) ans+=p1-p2+1;
	}
	cout<<ans;
	return 0;
}