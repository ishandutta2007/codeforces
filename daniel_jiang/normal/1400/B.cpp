/*
***


***
*/
#include<bits/stdc++.h>
#define swap(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
ll T,p,f,cnts,cntw,s,w,ans;
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
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
    while(T--){
    	rd(p);rd(f);rd(cnts);rd(cntw);rd(s);rd(w);ans=0;
        if(s>w) s^=w^=s^=w,cnts^=cntw^=cnts^=cntw;
        for(ll i=0;i<=cnts&&i*s<=p;++i){
            ll cnt=0,qaq=cnts,qwq=cntw,awa,qaqaq,qwqwq;
            cnt+=i;qaq-=i;
            awa=min((p-i*s)/w,qwq);
            cnt+=awa;qwq-=awa;
            qaqaq=min(f/s,qaq);
            cnt+=qaqaq;qaq-=qaqaq;
            qwqwq=min((f-qaqaq*s)/w,qwq);
            cnt+=qwqwq;
            ans=max(ans,cnt);
        }
        wr(ans);puts("");
    }
    return 0;
}