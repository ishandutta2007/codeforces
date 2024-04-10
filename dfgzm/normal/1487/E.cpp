#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=400010;
int i,j,k,n,m,T;
ll a[5][maxn],s[5];
struct dish{
	ll cost;
	int id;
}D[maxn];
struct hate{
	int id1,id2;
}H[maxn];
bool cmp(dish a,dish b){
	return a.cost<b.cost;
}
bool cmp2(hate a,hate b){
	return a.id2<b.id2;
}
bool is[maxn];
int main(){
	for(i=1;i<=4;i++)s[i]=read();
	for(i=1;i<=4;i++)
		for(j=1;j<=s[i];j++)a[i][j]=read();
	for(i=1;i<=3;i++){
		for(j=1;j<=s[i];j++)D[j]={a[i][j],j};
		sort(D+1,D+1+s[i],cmp);
		int num=read();
		for(j=1;j<=num;j++)H[j]={read(),read()};
		sort(H+1,H+1+num,cmp2);
		int q=1,last=1;
		for(j=1;j<=s[i+1];j++){
			while(q<=num&&H[q].id2==j)is[H[q].id1]=true,++q;
			for(k=1;k<=s[i];k++)
				if(!is[D[k].id])break;
			if(k!=s[i]+1 && D[k].cost<2000000000)a[i+1][j]+=D[k].cost;
			else a[i+1][j]=2000000000;
//			cout<<a[i+1][j]<<' ';
			for(k=last;k<q;k++)is[H[k].id1]=false;
			last=q;
		}//cout<<endl;
	}
	ll ans=2e9;
	for(i=1;i<=s[4];i++)ans=min(ans,a[4][i]);
	cout<<(ans>=2000000000?-1:ans)<<endl;
	return 0;
}
/*
4 3 2 1
1 2 3 4
50 60 70
800 900
1000
2
1 1
1 2
4
2 1
1 2
1 1
3 1
1
1 1
*/