/*
***


***
*/
#include<bits/stdc++.h>
#pragma optimize(3)
using namespace std;
typedef long long ll;
ll t,k,a,b;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	rd(t);rd(k);
	while(t--){
		rd(a);rd(b);
		if(k==1){
			if(a&b&1) putchar('-');
			else putchar('+');
			puts("");
			continue;
		}
		if(a<b) a^=b,b^=a,a^=b;
		if(b%(k+1)==0){putchar('+');puts("");continue;}
		if((((a-b+b%(k+1))&1)^((b%(k+1))&1))^((b/(k+1))&1)) putchar('+');
		else putchar('-');
		puts("");
	}
	return 0;
}