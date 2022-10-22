#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=1e9+9,k=1000007;typedef ll aN[N];aN p,c,hs;ll flag=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}ll cmp(ll u,ll v){return hs[u]<hs[v];}
ll pow(ll a,ll b,ll p){ll ans=1;while(b){if(b&1)ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
ll calc(ll cases){
//if(flag)printf("f=%lld\n",flag);
    ll n=readll(),m=readll(),ans=0,lst=0,u,v,x;rep(i,1,n)c[p[i]=i]=readll(),hs[i]=0;(void)cases;
    rep(i,1,m)u=readll(),v=readll(),hs[v]=(hs[v]+pow(u,mod-2,mod))%mod;std::sort(p+1,p+n+1,cmp);hs[p[n+1]=n+1]=-1;
//    rep(i,1,n)printf("hs[%lld]=%lld\n",i,hs[i]);
    rep(i,1,n+1)if(hs[x=p[i]])hs[x]!=hs[p[i-1]]?ans=gcd(ans,lst),lst=c[x]:lst+=c[x];return ans;
}
int main(){ll T=readll(),cnt=0;while(T --> 0)printf("%lld\n",calc(++cnt));return 0;}
/*
1
128 128
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
2 1
3 1
5 1
8 1
9 1
12 1
14 1
15 1
17 1
20 1
22 1
23 1
26 1
27 1
29 1
32 1
33 1
36 1
38 1
39 1
42 1
43 1
45 1
48 1
50 1
51 1
53 1
56 1
57 1
60 1
62 1
63 1
65 1
68 1
70 1
71 1
74 1
75 1
77 1
80 1
82 1
83 1
85 1
88 1
89 1
92 1
94 1
95 1
98 1
99 1
101 1
104 1
105 1
108 1
110 1
111 1
113 1
116 1
118 1
119 1
122 1
123 1
125 1
128 1
1 2
4 2
6 2
7 2
10 2
11 2
13 2
16 2
18 2
19 2
21 2
24 2
25 2
28 2
30 2
31 2
34 2
35 2
37 2
40 2
41 2
44 2
46 2
47 2
49 2
52 2
54 2
55 2
58 2
59 2
61 2
64 2
66 2
67 2
69 2
72 2
73 2
76 2
78 2
79 2
81 2
84 2
86 2
87 2
90 2
91 2
93 2
96 2
97 2
100 2
102 2
103 2
106 2
107 2
109 2
112 2
114 2
115 2
117 2
120 2
121 2
124 2
126 2
127 2
*/