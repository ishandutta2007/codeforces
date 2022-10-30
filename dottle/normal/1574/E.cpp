#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;

int hc[2][N],lc[2][N],h2,h0,l2,l0,isa,isb;
int n,m,k,x,y,z;
map<int,int> a[N];

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

void del(int x,int y,int c){
	if(!c)return;
	c--;
	if(lc[0][y]&&lc[1][y])l0--;
	lc[c^(x&1)][y]--;
	if(lc[0][y]&&lc[1][y])l0++;
	if(!lc[0][y]&&!lc[1][y])l2++;
	
	if(hc[0][x]&&hc[1][x])h0--;
	hc[c^(y&1)][x]--;
	if(hc[0][x]&&hc[1][x])h0++;
	if(!hc[0][x]&&!hc[1][x])h2++;
	
	if((c^x^y)&1)isa--;
	else isb--;
}

void add(int x,int y,int c){
	if(!c)return;
	c--;
	if(!lc[0][y]&&!lc[1][y])l2--;
	if(lc[0][y]&&lc[1][y])l0--;
	lc[c^(x&1)][y]++;
	if(lc[0][y]&&lc[1][y])l0++;
	if(!lc[0][y]&&!lc[1][y])l2++;
	
	if(!hc[0][x]&&!hc[1][x])h2--;
	if(hc[0][x]&&hc[1][x])h0--;
	hc[c^(y&1)][x]++;
	if(hc[0][x]&&hc[1][x])h0++;
	if(!hc[0][x]&&!hc[1][x])h2++;
	
	if((c^x^y)&1)isa++;
	else isb++;
}

int calc(){
	int ans=0;
	if(!h0)ans=ans+gsc(2,h2);
	if(!l0)ans=ans+gsc(2,l2);
	if(!isa)ans--;
	if(!isb)ans--;
	return ans%mod;
}

main(){
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	h2=n,l2=m;
	for(int i=1;i<=k;i++){
		cin>>x>>y>>z;
		del(x,y,a[x][y]);
		a[x][y]=z+1;
		add(x,y,z+1);
		cout<<calc()<<endl;
	}
}