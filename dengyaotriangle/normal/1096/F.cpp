#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const long long mdn=998244353;

int n;
int id[maxn];
int p[maxn];
int pfx[maxn];
vector<int> q;
int bit[maxn];

void chg(int i,int x){
	while(i<maxn){
		bit[i]+=x;
		i+=i&(-i); 
	}
} 
int qry(int i){
	int ans=0;
	while(i){
		ans+=bit[i];
		i-=i&(-i); 
	}
	return ans;
}
long long ksm(long long bse,long long ex){
	if(ex==0)return 1;
	long long ans=ksm(bse,ex>>1);ans=(ans*ans)%mdn;
	if(ex&1)ans=(ans*bse)%mdn;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)if(p[i]!=-1)q.push_back(p[i]); 
	memset(id,-1,sizeof(id));
	for(int i=1;i<=n;i++)if(p[i]!=-1)id[p[i]]=i;		
	for(int i=1;i<=n;i++)pfx[i]=pfx[i-1]+(int)(p[i]==-1);
	//cout<<pfx[n]<<endl;
	long long sm=(((ksm(4,mdn-2)*pfx[n])%mdn)*(long long)(pfx[n]-1))%mdn,cur=0;
	for(int i=1;i<=n;i++){
		if(id[i]==-1){
			sm+=cur*ksm(pfx[n],mdn-2);
			sm%=mdn; 
		}else{
			cur+=pfx[id[i]];
		}
	}
	cur=0;
	for(int i=n;i>=1;i--){
		if(id[i]==-1){
			sm+=cur*ksm(pfx[n],mdn-2);
			sm%=mdn; 
		}else{
			cur+=pfx[n]-pfx[id[i]];
		}
	}
	for(int i=q.size()-1;i>=0;i--){
		sm+=qry(q[i]);
		chg(q[i],1);
	}
	cout<<(sm%mdn); 
	return 0;
}