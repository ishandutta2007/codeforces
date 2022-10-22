#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ld eps=1e-6,inf=1e9;const ll N=1e5+5;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ld x,y;};int eq(ld x,ld y){return fabs(x-y)<eps;}int cmp(ld a,ld b){return eq(a,b)?0:a<b;}
struct tb{
	struct ptdq{
	    ll zx,zy,k,size;static const ll N=114514;pt val[N];ll h,t;void clear(){zx=zy=k=size=t=0,h=1;}ptdq(){clear();}
		#define inc(x) (++x==N?x=0:x)
		#define dec(x) (--x==-1?x=N-1:x)
		pt top_front()const{return val[h];}pt top_back()const{return val[t];}
		void push_front(pt x){val[dec(h)]=x,size++;}void push_back(pt x){val[inc(t)]=x,size++;}
		void pop_front(){inc(h),size--;}void pop_back(){dec(t),size--;}
		pt real_point(pt x)const{return(pt){x.x+k*x.y+zx,x.y+zy};}
        pt fake_point(pt x)const{return(pt){x.x-k*x.y-zx+k*zy,x.y-zy};}
//x=x'+ky'+zx
//y=y'+zy
//x-ky=x'+zx-kzy
//x'=x-ky-zx+kzy
//y'=y-zy 
        pt real_front(){return real_point(top_front());}pt real_back(){return real_point(top_back());}
        void fake_front(pt x){return push_front(fake_point(x));}void fake_back(pt x){return push_back(fake_point(x));}
        void print()const{
            if(size==0)return;
            ll x=h;while(x!=t)printf("(%.3lf,%.3lf)\n",(double)real_point(val[x]).x,(double)real_point(val[x]).y),inc(x);
            printf("(%.3lf,%.3lf)\n",(double)real_point(val[t]).x,(double)real_point(val[t]).y);
        }
	}st,xt;
	void cq(){
	    ll flag_back=!eq(xt.real_back().y,st.real_back().y),
        flag_front=!eq(xt.real_front().y,st.real_front().y);
//	    puts("cq="),print();
        st.zx+=st.zy,st.k++,xt.zx+=xt.zy,xt.k++;
//	    puts("cq="),print();
        if(flag_back)xt.fake_back(st.real_back());if(flag_front)st.fake_front(xt.real_front());
    }
	void py(ll zd,ll zu){
	    ll flag_back=1,//!eq(xt.real_back().y,st.real_back().y),
        flag_front=1;//!eq(xt.real_front().y,st.real_front().y);
//        pt p_front=st.real_front(),p_back=xt.real_back();
        st.zx+=zu,st.zy+=zu,xt.zx+=zd,xt.zy+=zd;
        if(flag_front)st.fake_front(xt.real_front());if(flag_back)xt.fake_back(st.real_back());
//        puts("py="),print();
//        printf("ss=%lld %lld %lld(%.3Lf,%.3Lf)(%.3Lf,%.3Lf)(%.3Lf,%.3Lf)",st.zx,st.zy,st.k,p_front.x,p_front.y,
//        st.fake_point(p_front).x,st.fake_point(p_front).y,
//        st.real_point(st.fake_point(p_front)).x,st.real_point(st.fake_point(p_front)).y);
//        puts("py2="),print();
//        puts("pyt3"); 
	}
	void limit(ll xd,ll xu,ll yd,ll yu){
	    pt now,lst;ll f;ld k,dx;
//	    printf("x in[%lld,%lld],y in[%lld,%lld]\n",xd,xu,yd,yu);
//        puts("now:"),print();
        for(f=0,now=st.real_front();st.size&&cmp(now.y,yd);st.pop_front(),lst=now,f=1,now=st.real_front());
        if(st.size&&f&&cmp(yd,now.y))k=(now.y-lst.y)/(now.x-lst.x),dx=(yd-now.y)/k,st.fake_front((pt){now.x+dx,now.y+dx*k});
//        puts("1:"),print();
        for(f=0,now=xt.real_front();xt.size&&cmp(now.y,yd);xt.pop_front(),lst=now,f=1,now=xt.real_front());
        if(xt.size&&f&&cmp(yd,now.y))k=(now.y-lst.y)/(now.x-lst.x),dx=(yd-now.y)/k,xt.fake_front((pt){now.x+dx,now.y+dx*k});
        if(!xt.size&&f&&eq((now=st.real_back()).x,lst.x)&&cmp(yd,now.y))xt.fake_front((pt){now.x,(ld)yd});
        
//        puts("2:"),print();
        now=st.real_front(),lst=xt.real_front();
        if(eq(now.y,lst.y)&&cmp(now.x,lst.x))xt.fake_front(now);
        for(f=0,now=st.real_back();st.size&&cmp(yu,now.y);st.pop_back(),lst=now,f=1,now=st.real_back());
        if(st.size&&f&&cmp(now.y,yu))k=(now.y-lst.y)/(now.x-lst.x),dx=(yu-now.y)/k,st.fake_back((pt){now.x+dx,now.y+dx*k});
        if(!st.size&&f&&eq((now=xt.real_front()).x,lst.x)&&cmp(now.y,yu))st.fake_back((pt){now.x,(ld)yu});
//        printf("fseagknrslgsnd=%.3Lf\n",dx);
//        printf("%d %.3Lf %.3Lf %.3Lf | %.3Lf %.3Lf\n",f&&cmp(now.y,yu),now.x+dx,now.y+dx*k,(ld)k,(yu-now.y)/k,dx);
        for(f=0,now=xt.real_back();xt.size&&cmp(yu,now.y);xt.pop_back(),lst=now,f=1,now=xt.real_back());
        if(xt.size&&f&&cmp(now.y,yu))k=(now.y-lst.y)/(now.x-lst.x),dx=(yu-now.y)/k,xt.fake_back((pt){now.x+dx,now.y+dx*k});
//        puts("2:"),print();
        now=st.real_back(),lst=xt.real_back();
        if(eq(now.y,lst.y)&&cmp(now.x,lst.x))st.fake_back(lst);
        
//        puts("2:"),print();
        for(f=0,now=st.real_front();st.size&&cmp(now.x,xd);st.pop_front(),lst=now,f=1,now=st.real_front());
        if(st.size&&f&&cmp(xd,now.x))k=(now.y-lst.y)/(now.x-lst.x),dx=xd-now.x,st.fake_front((pt){now.x+dx,now.y+dx*k});
        for(f=0,now=xt.real_front();xt.size&&cmp(now.x,xd);xt.pop_front(),lst=now,f=1,now=xt.real_front());
        if(xt.size&&f&&cmp(xd,now.x))k=(now.y-lst.y)/(now.x-lst.x),dx=xd-now.x,xt.fake_front((pt){now.x+dx,now.y+dx*k});
        
        for(f=0,now=st.real_back();st.size&&cmp(xu,now.x);st.pop_back(),lst=now,f=1,now=st.real_back());
        if(st.size&&f&&cmp(now.x,xu))k=(now.y-lst.y)/(now.x-lst.x),dx=xu-now.x,st.fake_back((pt){now.x+dx,now.y+dx*k});
        for(f=0,now=xt.real_back();xt.size&&cmp(xu,now.x);xt.pop_back(),lst=now,f=1,now=xt.real_back());
        if(xt.size&&f&&cmp(now.x,xu))k=(now.y-lst.y)/(now.x-lst.x),dx=xu-now.x,xt.fake_back((pt){now.x+dx,now.y+dx*k});
//        puts("end:"),print();
	}
	int empty()const{return!st.size||!xt.size;}void clear(){st.clear(),xt.clear();}
    void cs(ld xd,ld xu){
        st.push_back((pt){xd,inf}),xt.push_back((pt){xd,-inf});
        if(cmp(xd,xu))st.push_back((pt){xu,inf}),xt.push_back((pt){xu,-inf});
    }
    void print()const{puts("st="),st.print(),puts("xt="),xt.print();}
}t;aN xd,xu,yd,yu,zd,zu;

int main(){
	ll T=readll();
	rep(j,1,T){
		ll n=readll(),flag=1;
		rep(i,1,n)xd[i]=readll(),xu[i]=readll();
		rep(i,2,n)yd[i]=readll(),yu[i]=readll();
		rep(i,3,n)zd[i]=readll(),zu[i]=readll();
//	    if(T==33333&&j==29){
//	        puts("input:");
//	        printf("%lld\n",n);
//	        rep(i,1,n)printf("%lld %lld\n",xd[i],xu[i]);
//	        rep(i,2,n)printf("%lld %lld\n",yd[i],yu[i]);
//	        rep(i,3,n)printf("%lld %lld\n",zd[i],zu[i]);
//        }
		t.clear(),t.cs(xd[1],xu[1]);//t.print();puts("");
		rep(i,2,n){
		    t.cq();/*t.print();puts("");*/if(i>=3)t.py(zd[i],zu[i]);
//		    t.print();puts("");
		    t.limit(xd[i],xu[i],yd[i],yu[i]);if(t.empty()){flag=0;break;}
//		    t.print();puts("");
        }
	    /*if(T==33333&&j==29){
	        puts("output");
            puts(flag?"YES":"NO");
        }
        if(T!=33333)*/puts(flag?"YES":"NO");
	}
	return 0;
}
/*
4
3
0 1
0 1
0 1
1 1
1 1
-100 100
3
-967 541
-500 834
-724 669
-858 978
-964 962
-645 705
4
0 0
0 1
0 1
1 1
0 1
0 1
0 1
0 0
0 0
4
0 0
33 34
65 66
100 100
0 100
0 100
0 100
0 0
0 0
*/
//       o    o
//   o        o
// o         o
//o        o
//      o
//o o
//	pt sed_front()const{return val[h==0?N-1:h-1];}pt sed_back()const{return val[t==N-1?0:t+1];}
//	void cq(){
//        st.zx+=st.zy,st.k++,xt.zx+=xt.zy,xt.k++;
//        if(eq(st.real_point(st.top_back()).x,st.real_point(st.sed_back()).x))
//        xt.push_back(xt.fake_point(st.real_point(st.top_back()))),st.pop_back();
//        if(eq(xt.real_point(xt.top_front()).x,xt.real_point(xt.sed_front()).x))
//        st.push_front(st.fake_point(xt.real_point(xt.top_front()))),xt.pop_front();
//    }
//	void py(ll zd,ll zu){
//        st.zx+=zu,st.zy+=zu,xt.zx+=zd,xt.zy+=zd,
//        st.push_front(st.fake_point(xt.real_point(xt.top_front()))),
//        xt.push_back(xt.fake_point(st.real_point(st.top_back())));
//	}
/*

	void limit(ll xd,ll xu,ll yd,ll yu){
	    pt now,lst;ll f;ld k,dx;
//	    printf("%lld %lld %lld %lld\n",xd,xu,yd,yu);
        for(f=0,now=st.real_front();st.size&&(cmp(now.x,xd)||cmp(now.y,yd));st.pop_front(),lst=now,f=1,now=st.real_front());
        if(f&&cmp(xd,now.x)&&cmp(yd,now.y))k=(now.y-lst.y)/(now.x-lst.x),dx=std::max(k?(yd-now.y)/k:-inf,xd-now.x),
        st.fake_front((pt){now.x+dx,now.y+dx*k});
//        printf("%.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf %.3Lf\n",now.x,dx,now.y,dx*k,yd,now.y,xd-now.x);
//        puts("1:"),print();
        for(f=0,now=st.real_back();st.size&&(cmp(xu,now.x)||cmp(yu,now.y));st.pop_back(),lst=now,f=1,now=st.real_back());
//        puts("2:"),print();
        if(f&&cmp(now.x,xu)&&cmp(now.y,yu))k=(now.y-lst.y)/(now.x-lst.x),dx=std::min(k?(yu-now.y)/k:inf,xu-now.x),
        st.fake_back((pt){now.x+dx,now.y+dx*k});
//        puts("2:"),print();
        for(f=0,now=xt.real_front();xt.size&&(cmp(now.x,xd)||cmp(now.y,yd));xt.pop_front(),lst=now,f=1,now=xt.real_front());
        if(f&&cmp(xd,now.x)&&cmp(yd,now.y))k=(now.y-lst.y)/(now.x-lst.x),dx=std::max(k?(yd-now.y)/k:-inf,xd-now.x),
        xt.fake_front((pt){now.x+dx,now.y+dx*k});
//        printf("%.3Lf\n",dx);
//        puts("3:"),print();
        for(f=0,now=xt.real_back();xt.size&&(cmp(xu,now.x)||cmp(yu,now.y));xt.pop_back(),lst=now,f=1,now=xt.real_back());
        if(f&&cmp(now.x,xu)&&cmp(now.y,yu))k=(now.y-lst.y)/(now.x-lst.x),dx=std::min(k?(yu-now.y)/k:inf,xu-now.x),
        xt.fake_back((pt){now.x+dx,now.y+dx*k});
//        puts("4:"),print();
        if(!st.size)
        now=st.real_front(),lst=xt.real_front();
        if(eq(now.y,lst.y)&&cmp(now.x,lst.x))xt.fake_front(now);
        now=st.real_back(),lst=xt.real_back();
        if(eq(now.y,lst.y)&&cmp(now.x,lst.x))st.fake_front(lst);
//        puts("5:"),print();
	}
*/
/*
1
6
5130181 84555501
-33949731 17090802
-90229539 -21005762
16786548 79025964
-32639118 -23050876
19160861 51560741

-33425305 73426125
-1016365 -311776
-76730924 31197966
-6880527 37956303
-80103614 82590132

-74405082 81290458
62078331 77587383
-57651972 -21497816
6232213 63074687
*/
/*
1
9
0 1
0 3
0 3
0 1
0 3
0 3
1 2
1 3
0 3
0 3
-1 2
-3 1
-3 2
-3 0
-1 3
1 3
-1 2
-5 -3
-1 3
-5 0
-1 -1
-5 6
-4 0
-2 2
*/