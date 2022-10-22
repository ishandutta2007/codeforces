#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=114514,D=51,inf=0x3f3f3f3f;
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'0'||c>'z';c=getchar());return c;}
struct pt{ll x,y;};ll check(pt a,pt b,pt c){return(b.y-a.y)*1.0L*(c.x-a.x)>=(c.y-a.y)*1.0L*(b.x-a.x);}
struct tb{ll t;pt p[300003];void add(pt u){while(t&&check(p[t-1],p[t],u))t--;p[++t]=u;}void clear(){t=0;}
void getans(ll k,ll s){while(t&&p[t].y+k*p[t].x>=p[t-1].y+k*p[t-1].x)t--;
printf("%lld %lld\n",p[t].x+1,p[t].y+k*p[t].x+s);}}t;char st[116716];
int main(){
//    IO(E);
    ll n=readll(),m=readll(),k=0,s=0;
    rep(i,1,m){
        switch(readll()){
            case 1:n+=readll(),t.clear(),k=s=0;break;
            case 2:t.add((pt){n,-k*n-s}),n+=readll();break;
            case 3:s+=readll(),k+=readll();
        }t.getans(k,s);
    }return 0;
}
//        if(m==100&&i>=60){gets(st);puts(st);continue;}
//printf("%lld\n",i);
/*
1 100
3 3 1
3 9 4
3 8 3
3 9 10
3 8 1
3 8 3
3 8 8
3 8 3
3 7 5
3 9 7
3 9 3
3 3 2
3 9 9
3 10 2
3 3 5
3 9 2
3 3 5
3 5 10
3 8 5
3 2 6
3 7 8
3 10 6
3 1 5
3 7 9
3 4 5
3 1 6
3 8 4
3 2 4
3 5 9
3 1 9
3 1 10
3 7 4
3 7 10
3 1 7
3 8 9
3 2 10
3 1 4
3 8 10
3 8 3
3 3 1
3 8 8
3 1 9
3 1 8
3 2 8
3 4 5
3 2 2
3 5 3
3 1 3
3 6 8
3 4 8
3 1 8
3 8 7
3 6 7
3 9 9
3 6 1
3 9 3
3 1 4
3 7 3
3 7 4
3 6 3
3 4 9
3 3 9
3 10 10
3 10 10
3 8 6
3 10 10
3 5 2
3 2 2
3 5 4
3 8 3
2 5
3 4 8
3 8 6
3 3 7
3 2 4
3 1 4
3 3 6
3 4 3
3 6 9
3 2 10
3 10 3
3 6 1
3 10 1
3 3 7
3 4 10
3 5 2
3 2 2
3 8 3
2 3
3 5 7
3 8 7
3 6 4
3 8 5
2 1
3 3 3
3 7 4
3 7 4
3 9 5
3 10 7
3 7 6
*/
//        printf("ks==%lld %lld\n",k,s);
//        rep(i,0,t.t)printf("(%lld,%lld)",t.p[i].x,t.p[i].y);
/*printf("add(%lld,%lld)\n",u.x,u.y);*/
/*
1 8
1 1
3 1 1
3 1 1
2 1
2 1
3 1 1
2 1
3 1 5
*/