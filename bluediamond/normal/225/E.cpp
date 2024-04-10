#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=40+5;

const ll F=(int)1e8;

bitset<F>g;

ll f(ll x,ll y)
{
    return x/2+y+x*y;
}

ll slove(ll x)
{	if(x==1) return 1;
	if(x==2) return 3;
	if(x==3) return 15;
	if(x==4) return 63;
	if(x==5) return 4095;
	if(x==6) return 65535;
	if(x==7) return 262143;
	if(x==8) return 100000001;
	if(x==9) return 100000002;
	if(x==10) return 100000003;
	if(x==11) return 100000004;
	if(x==12) return 100000005;
	if(x==13) return 100000006;
	if(x==14) return 100000007;
	if(x==15) return 100000008;
	if(x==16) return 100000009;
	if(x==17) return 100000010;
	if(x==18) return 100000011;
	if(x==19) return 100000012;
	if(x==20) return 100000013;
	if(x==21) return 100000014;
	if(x==22) return 100000015;
	if(x==23) return 100000016;
	if(x==24) return 100000017;
	if(x==25) return 100000018;
	if(x==26) return 100000019;
	if(x==27) return 100000020;
	if(x==28) return 100000021;
	if(x==29) return 100000022;
	if(x==30) return 100000023;
	if(x==31) return 100000024;
	if(x==32) return 100000025;
	if(x==33) return 100000026;
	if(x==34) return 100000027;
	if(x==35) return 100000028;
	if(x==36) return 100000029;
	if(x==37) return 100000030;
	if(x==38) return 100000031;
	if(x==39) return 100000032;
	if(x==40) return 100000033;
	if(x==41) return 100000034;

}

void bnn()
{
    ll x;
    cin>>x;
    cout<<slove(x)<<"\n";
    exit(0);
}

int a[]={	2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951, 30402457, 32582657, 37156667, 42643801, 43112609};/// < 5
const int MOD=(int)1e9+7;

int add(int a,int b)
{
    a+=b;
    if(a>=MOD)
    {
        a-=MOD;
    }
    if(a<0)
    {
        a+=MOD;
    }
}

int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    cout<<expow(2,a[n-1]-1)-1<<"\n";
    return 0;
    for(int i=0;i<5;i++)
    {
        cout<<log2(a[i]+1)<<"\n";
    }
    return 0;
    bnn();
    freopen("data","w",stdout);
    for(ll x=1;x<=F;x++)
    {
        for(ll y=1;f(x,y)<=F;y++)
        {
            g[f(x,y)]=1;
        }
    }
    for(ll y=1;y<=F;y++)
    {
        for(ll x=1;f(x,y)<=F;x++)
        {
            g[f(x,y)]=1;
        }
    }
    int x=0;
    for(int i=1;x<=40;i++)
    {
        if(g[i]==0)
        {
            x++;
            cout<<"\tif(x=="<<x<<") return "<<i<<";\n";
        }
    }
    return 0;
}
/**

3,15,63,4095,65535,262143;

2,4,6,12,16

**/