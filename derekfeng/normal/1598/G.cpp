#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long ll;
int Ma,Mb,Mc,Md,Me;
struct Group{
	int a,b,c,d,e;
	Group(int a=0,int b=0,int c=0,int d=0,int e=0):a(a),b(b),c(c),d(d),e(e){}
	bool operator==(const Group &o){
		return a==o.a&&b==o.b&&c==o.c&&d==o.d&&e==o.e;
	}
	Group operator+(const Group &o){
		return Group((a+o.a)%Ma,(b+o.b)%Mb,(c+o.c)%Mc,(d+o.d)%Md,(e+o.e)%Me);
	}
	Group operator-(const Group &o){
		return Group((a+Ma-o.a)%Ma,(b+Mb-o.b)%Mb,(c+Mc-o.c)%Mc,(d+Md-o.d)%Md,(e+Me-o.e)%Me);
	}
	Group operator*(const int &o){
		return Group((ll)a*o%Ma,(ll)b*o%Mb,(ll)c*o%Mc,(ll)d*o%Md,(ll)e*o%Me);
	}
	Group operator*(const Group &o){
		return Group((ll)a*o.a%Ma,(ll)b*o.b%Mb,(ll)c*o.c%Mc,(ll)d*o.d%Md,(ll)e*o.e%Me);
	}
	Group operator+(const int &o){
		return Group((a+o)%Ma,(b+o)%Mb,(c+o)%Mc,(d+o)%Md,(e+o)%Me);
	}
};
int Rand(){
    int x=GetCurrentProcessId();
    x^=(int64_t)GetProcessHeap();
    x^=(int64_t)HeapAlloc(GetProcessHeap(),0,1);
    auto dummy=new char;
    x^=(int64_t)dummy;
    return x;
}
int random_prime(){
	const int MX=1e9;
	mt19937 rng(Rand());
	for(;;){
		int tmp=rng()%MX;
		if(tmp%2==0||tmp%3==0||tmp%5==0||tmp%7==0)continue;
		return tmp;
	}
}
Group p10[500005];
Group ha[500005],hb[200005],W;
char s[500005],t[200005],c[700005];
int z[700005],N;
int n,m,lcp[500005];
void Z(){
	int l=0,r=0;
	for(int i=1;i<N;i++){
		if(i>r){
			l=r=i;
			while(r<N&&c[r-l]==c[r])r++;
			z[i]=r-l,r--;
		}else{
			if(z[i-l]<r-i+1)z[i]=z[i-l];
			else{
				l=i;
				while(r<N&&c[r-l]==c[r])r++;
				z[i]=r-l,r--;
			}
		}
	}
}
void answer(int l1,int r1,int l2,int r2){
	int jw=0;
	for(int i=m,j=r1,k=r2;i;i--,j--,k--){
		if(j>=l1)jw+=s[j]-'0';
		if(k>=l2)jw+=s[k]-'0';
		if(jw%10!=t[i]-'0')return;
		jw/=10;
	}
	if(!jw){
		printf("%d %d\n%d %d",l1,r1,l2,r2);
		exit(0);
	}
}
void got(int l1,int r1,int l2,int r2){
	Group A=(ha[r1]-ha[l1-1]*p10[r1-l1]);
	Group B=(ha[r2]-ha[l2-1]*p10[r2-l2]);
	if((ha[r1]-ha[l1-1]*p10[r1-l1+1])+(ha[r2]-ha[l2-1]*p10[r2-l2+1])==W)
		answer(l1,r1,l2,r2);
}
void check(int l,int r,int d){
	if(d>0){
		got(l,r,r+1,r+d);
		got(l-d,l-1,l,r);
	}
}
void sol(int l,int r){
	if(r-l+1!=m){
		check(l,r,m);
		check(l,r,m-1);
	}else{
		int pos=l+lcp[l]-1;
		check(l,r,r-pos);
		check(l,r,r-pos-1);
	}
}
int main(){
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	Ma=1e9+9,Mb=998244353,Mc=19260817,Md=random_prime(),Me=random_prime();
	p10[0]=Group(1,1,1,1,1);
	for(int i=1;i<=n;i++)p10[i]=p10[i-1]*10;
	for(int i=1;i<=n;i++)ha[i]=ha[i-1]*10+(s[i]-'0');
	for(int i=1;i<=m;i++)hb[i]=hb[i-1]*10+(t[i]-'0');
	W=hb[m];
	for(int i=1;i<=m;i++)c[N++]=t[i];c[N++]='$';for(int i=1;i<=n;i++)c[N++]=s[i];
	Z();for(int i=1;i<=n;i++)lcp[i]=z[m+i];
	for(int i=1;i+m-1<=n;i++)sol(i,i+m-1);
	if(m>1)for(int i=1;i+m-2<=n;i++)sol(i,i+m-2);
}