#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=998244353;
using namespace std;

int n,m,mx=200000;
int s[N],t[N],cnt[N];

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

struct BIT{
    int a[N];
    void add(int k,int p){while(k<=mx)a[k]+=p,k+=k&-k;}
    int sum(int k){int ans=0;while(k)ans+=a[k],k-=k&-k;return ans;}
}T;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i],cnt[s[i]]++; 
	for(int i=1;i<=m;i++)cin>>t[i];
	init();
	int res=0,np=1;
	for(int i=1;i<=mx;i++)
		np=np*ij[cnt[i]]%mod,T.add(i,cnt[i]);
	int rst=n;
	for(int i=1;i<=m;i++){
		rst--;
		if(rst<0){
			res++;
			break;
		}
		res+=jc[rst]*np%mod*T.sum(t[i]-1)%mod;
		if(cnt[t[i]]==0)break;
		np=np*cnt[t[i]]%mod;
		cnt[t[i]]--;
		T.add(t[i],-1);
	}
	cout<<res%mod<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}