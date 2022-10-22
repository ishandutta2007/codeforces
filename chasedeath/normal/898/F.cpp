#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}


const ll P=19260817;//K=5567891;
const ll P1=1e9+13;//K1=6550879;
const int N=1e6+10;


int n;
char s[N];
ll h[N],h1[N];
ll po[N]={1},po1[N]={1};
//ll Inv[N]={1,13482572},Inv1[N]={1,300000004};


struct Pii{
	int x,y;
	Pii operator + (const Pii t) const{ 
		return (Pii){(int)((x+t.x)%P),(int)((y+t.y)%P1)};
	}
	bool operator == (const Pii t) const{
		return x==t.x&&y==t.y;
	}
};

Pii Get(int l,int r){
	ll t=(h[r]-h[l-1]*po[r-l+1]%P+2*P)%P;
	ll t1=(h1[r]-h1[l-1]*po1[r-l+1]%P1+2*P1)%P1;
	t=(t%P+P)%P;
	t1=(t1%P1+P1)%P1;
	return (Pii){(int)t,(int)t1};
}

int Check(int a,int b){
	//cout<<a<<' '<<b<<endl;
	if(s[a+1]=='0'&&b>a+1) return 0;
	if(s[b+1]=='0' && b<n-1) return 0;
	//cout<<Get(1,a).x<<' '<<Get(1,a).y<<endl;
	//cout<<Get(a+1,b).x<<' '<<Get(a+1,b).y<<endl;
	//cout<<Get(b+1,n).x<<' '<<Get(b+1,n).y<<endl;
	return Get(1,a)+Get(a+1,b)==Get(b+1,n);
}

/*
void Exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){ 
		x=1,y=0;
		return;
	}
	Exgcd(b,a%b,y,x);y-=a/b*x;
}
*/

//15 72
//814752277691991+477306861346922924221557534659480258977017038624458370459=477306861346922924221557534659480258977017853376736062450
int main(){
	rep(i,1,N-1) {
		po[i]=po[i-1]*10%P;
		po1[i]=po1[i-1]*10%P1;
		//Inv[i]=Inv[i-1]*Inv[1]%P;
		//Inv1[i]=Inv1[i-1]*Inv1[1]%P1;
		//if(Inv[i]*po[i]%P!=1) return 0;
		//if(Inv1[i]*po1[i]%P1!=1) return 0;
	}
	//cout<<(457774ll+18084529)%19260817<<endl;
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n) {
		h[i]=(h[i-1]*10+(s[i]-'0'))%P;
		h1[i]=(h1[i-1]*10+(s[i]-'0'))%P1;
	}
	ll h=0;
	rep(i,73,n) h=(h*10+s[i]-'0')%P1;
	//rep(i,1,15) cout<<s[i];puts("");
	//rep(i,16,72) cout<<s[i];puts("");
	//rep(i,73,n) cout<<s[i];puts("");
	//cout<<h<<endl;
	int a=-1,b=-1;
	//cout<<s[11]<<s[12]<<' '<<s[71]<<s[72]<<endl;
	//cout<<Check(15,72);
	//return 0;
	drep(i,n,n/2) {
		if(n-i+1>0 && n-i+1<i-1 && Check(n-i+1,i-1)) a=n-i+1,b=i-1;
		if(n-i>0 && n-i<i-1 && Check(n-i,i-1)) a=n-i,b=i-1;
		//if(i==73) cout<<(i-(n-i+1))<<endl;
		if(i-(n-i+1)>0 && i-(n-i+1)<i-1 && Check(i-(n-i+1),i-1)) a=i-(n-i+1),b=i-1;
		if(i>(n-i+2) && i-(n-i+2)<i-1 && Check(i-(n-i+2),i-1)) a=i-(n-i+2),b=i-1;
		//if(Check(i,n-i)) a=i,b=n-i;
		//if(i<n-i-1 && Check(i,n-i-1)) a=i,b=n-i;
	}
	rep(i,1,n) {
		putchar(s[i]);
		if(a==i) putchar('+');
		if(b==i) putchar('=');
	}
}