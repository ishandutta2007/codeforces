#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=3e5;
int n,a[200004];
ll ans;
ll bit1[300004];
ll bit2[300004];
int bit3[300004];
int bit4[300004];
void upd1(int id,int x){for(;id;id-=(id&-id))bit1[id]+=x;}
void qry1(int l,int r,int x){upd1(l-1,-x),upd1(r,x);}
ll got1(int id){ll res=0;for(;id<=M;id+=(id&-id))res+=bit1[id];return res;}
void upd2(int id,int x){for(;id<=M;id+=(id&-id))bit2[id]+=x;}
ll got2(int id){ll res=0;for(;id;id-=(id&-id))res+=bit2[id];return res;}
ll qry2(int l,int r){return got2(r)-got2(l-1);}
void upd3(int id,int x){for(;id;id-=(id&-id))bit3[id]+=x;}
void qry3(int l,int r){upd3(l-1,-1),upd3(r,1);}
int got3(int id){int res=0;for(;id<=M;id+=(id&-id))res+=bit3[id];return res;}
void upd4(int id,int x){for(;id<=M;id+=(id&-id))bit4[id]+=x;}
int got4(int id){int res=0;for(;id;id-=(id&-id))res+=bit4[id];return res;}
int qry4(int l,int r){return got4(r)-got4(l-1);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans+=(ll)got3(a[i])*a[i]-got1(a[i]);
		for(int j=0,k=a[i]-1;j<=M;j+=a[i],k+=a[i]){
			int L=max(j,1),R=min(k,M);
			ans+=qry2(L,R)-(ll)qry4(L,R)*j;
			qry1(L,R,j),qry3(L,R);
		}
		upd2(a[i],a[i]),upd4(a[i],1);
		printf("%I64d ",ans);
	}
}