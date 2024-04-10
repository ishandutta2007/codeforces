// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
using ll=long long;
const int MOD = 998244353;

struct basis{
	int x[22];
	void clr(){
		rep(i,22)x[i]=0;
	}
	void ins(int v){
		for(int i=21;i>=0;i--)if(v&(1<<i)){
			if(!x[i]){x[i]=v;break;}
			v^=x[i];
		}
	}
	basis operator+(const basis& o){
		basis q=*this;
		rep(i,22)if(o.x[i])q.ins(o.x[i]);
		return q;
	}
	int fmax(){
		int z=0;
		for(int i=21;i>=0;i--)if(!(z&(1<<i)))z^=x[i];
		return z;
	}
};

basis L[300005], R[300005];
int ans[500005],ar[500005];
int ql[500005],qr[500005];
void proc(int l,int r,vector<int>qs){
	if(!qs.size())return;
	int m=(l+r)/2;
	vector<int>lef,rig,here;
	for(int i:qs){
		if(qr[i]<=m)lef.push_back(i);
		else if(m<=ql[i])rig.push_back(i);
		else here.push_back(i);
	}
	proc(l,m,lef);proc(m,r,rig);
	for(int i=m-l-1;i>=0;i--){
		if(i!=m-l-1)L[i]=L[i+1];
		else L[i].clr();
		L[i].ins(ar[l+i]);
	}
	rep(i,r-m){
		if(i)R[i]=R[i-1];
		else R[i].clr();
		R[i].ins(ar[m+i]);
	}
	for(int i:here){
		int a=ql[i]-l,b=qr[i]-m-1;
		ans[i]=(L[a]+R[b]).fmax();
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;cin>>n;
    rep(i,n)cin>>ar[i];
    int q;cin>>q;
    vector<int>qs;
    rep(i,q){
    	cin>>ql[i]>>qr[i];
    	ql[i]--;
    	if(qr[i]-ql[i]==1)ans[i]=ar[ql[i]];
    	else qs.push_back(i);
    }
    proc(0,n,qs);
    rep(i,q)cout<<ans[i]<<'\n';
}