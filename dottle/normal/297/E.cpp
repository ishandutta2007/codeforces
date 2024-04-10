#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)>>1)
const int N=400005;
using namespace std;

int n,l[N],r[N],nx[N];
int s[N],sm;

signed L[N<<5],R[N<<5],T[N],S[N<<5],cnt;

int updt(int pr,int l,int r,int x){
	int k=++cnt;
	L[k]=L[pr],R[k]=R[pr],S[k]=S[pr]+1;
	if(l^r)
		if(x<=mid)L[k]=updt(L[pr],l,mid,x);
		else R[k]=updt(R[pr],mid+1,r,x);
	return k;
}

int qry(int k,int l,int r,int x,int y){
	if(!k||r<x||l>y)return 0;
	if(r<=y&&l>=x)return S[k];
	return qry(L[k],l,mid,x,y)+qry(R[k],mid+1,r,x,y); 
}

int sum(int l,int r,int x,int y){
	return qry(T[r],1,sm,x,y)-qry(T[l-1],1,sm,x,y);
}

void solve(){
	cin>>n;sm=n<<2;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		if(l[i]>r[i])swap(l[i],r[i]);
		nx[l[i]]=r[i];
		nx[r[i]]=l[i]+2*n;
		nx[l[i]+2*n]=r[i]+2*n;
	}
	for(int i=1;i<=sm;i++)
		T[i]=updt(T[i-1],1,sm,nx[i]);
	int ans=n*(n-1)*(n-2)/6,su=0;
	for(int i=1;i<=n;i++){
		int s1=sum(l[i]+1,r[i]-1,l[i]+1,r[i]-1);
		int s2=sum(r[i]+1,l[i]+2*n-1,r[i]+1,l[i]+2*n-1);
		int s3=r[i]-l[i]-1;
		int s4=2*n-2-s3;
		su+=s1*(s4-s2*2)+s2*(s3-s1*2)+2*s1*s2;
	}
	cout<<ans-su/2<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}