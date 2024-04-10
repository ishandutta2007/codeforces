// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

int n,a,x1=1,y1=1,x3=1,y3=2,cnt1,cnt3;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=0;i<n*n;++i){
		rd(a);
		if(a==2){
			if(cnt1<(n*n+1)/2){
				cout<<1<<' '<<x1<<' '<<y1<<endl;
				y1+=2;cnt1++;
				if(y1>n) x1++,y1=((y1&1)?2:1);
			}
			else{
				cout<<3<<' '<<x3<<' '<<y3<<endl;
				y3+=2;cnt3++;
				if(y3>n) x3++,y3=((y3&1)?2:1);
			}
		}
		else if(a==1){
			if(cnt3<(n*n)/2){
				cout<<3<<' '<<x3<<' '<<y3<<endl;
				y3+=2;cnt3++;
				if(y3>n) x3++,y3=((y3&1)?2:1);
			}
			else{
				cout<<2<<' '<<x1<<' '<<y1<<endl;
				y1+=2;cnt1++;
				if(y1>n) x1++,y1=((y1&1)?2:1);
			}
		}
		else{
			if(cnt1<(n*n+1)/2){
				cout<<1<<' '<<x1<<' '<<y1<<endl;
				y1+=2;cnt1++;
				if(y1>n) x1++,y1=((y1&1)?2:1);
			}
			else{
				cout<<2<<' '<<x3<<' '<<y3<<endl;
				y3+=2;cnt3++;
				if(y3>n) x3++,y3=((y3&1)?2:1);
			}
		}
	}
	return 0;
}

// ---------- Main ---------- //