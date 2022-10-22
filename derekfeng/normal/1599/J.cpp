#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define rep(i,n) for(int i=0;i<n;++i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int lzk[1005],xuq[30],jyh[30],lyx,ftq;
bitset<28000006>lyn[28];
int wjy[17000],syr[17000];
void getvector(){
	for(int i=0;i<(1<<14);i++)
		for(int j=0;j<14;j++)if((1<<j)&i)wjy[i]+=lzk[j];
	for(int i=0;i<(1<<14);i++)
		for(int j=0;j<14;j++)if((1<<j)&i)syr[i]+=lzk[j+14];
	lyx=min(lyx,27);
	int sum=-1;
	for(int i=1;i<(1<<lyx);i++){
		int s=wjy[i&((1<<14)-1)]+syr[i>>14],cnt=__builtin_popcount(i);
		if(lyn[cnt][s]){
			sum=s,ftq=cnt;
			break;
		}
		lyn[cnt][s]=1;
	}
	if(sum<0)return;
	int f=0;
	for(int i=1;i<(1<<lyx);i++){
		int cnt=__builtin_popcount(i);
		if(cnt!=ftq)continue;
		int s=wjy[i&((1<<14)-1)]+syr[i>>14];
		if(s==sum){
			if(f==0){
				int ms=0;
				for(int j=0;j<lyx;j++)if((1<<j)&i)xuq[ms++]=lzk[j];
				++f;
			}else if(f==1){
				int ms=0;
				for(int j=0;j<lyx;j++)if((1<<j)&i)jyh[ms++]=lzk[j];
				++f;
			}
			if(f==2)return;
		}
	}
}

int n,b[1010],bas;
bool vis[1010];
vector <int> o,e;

void era(int x)
{
  rep(i,n) if(b[i]==x&& !vis[i])
  {
    vis[i]=true;
    break;
  }
}

int main()
{
  cin>>n;lyx=n;
  rep(i,n)
  {
    cin>>b[i];lzk[i]=b[i];
    if(b[i]%2==1) o.pb(b[i]);
    else e.pb(b[i]);
  }
  int a0,a1,a2,ok=0;
  if(o.size()>=2&&e.size()>0) a0=o[0],a1=o[1],a2=e[0],ok=1;
  else if(e.size()>2) a0=e[0],a1=e[1],a2=e[2],ok=1;
  if(ok)
  {
    era(a0);era(a1);era(a2);
    int x=(a2-a1+a0)/2;
    puts("YES");
    cout<<x<<' '<<a0-x<<' '<<a2-x<<' ';
    rep(i,n) if(!vis[i]) cout<<b[i]-x<<' ';
    cout<<endl;
  }
  else
  {
    getvector();
    if(ftq==0)
    {
      puts("NO");
      return 0;
    }
    int cur=0;
    rep(i,ftq)
    {
      lzk[cur++]=xuq[i];era(xuq[i]);
      lzk[cur++]=jyh[i];era(jyh[i]);
    }
    puts("YES");
    int x=0;cout<<x<<' ';
    rep(i,ftq+ftq-1)
    {
      x=lzk[i]-x;
      cout<<x<<' ';
    }
    rep(i,n) if(!vis[i]) cout<<b[i]-x<<' ';
    cout<<endl;
  }
  return 0;
}