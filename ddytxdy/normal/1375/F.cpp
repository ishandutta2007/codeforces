#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
using namespace std;
pii a[3];LL x,y,z,v;
int main(){
    scanf("%lld%lld%lld",&x,&y,&z);
    a[0]=mp(x,1);a[1]=mp(y,2);a[2]=mp(z,3);
    puts("First");cout.flush();
    while(1){
        sort(a,a+3);x=a[0].fi,y=a[1].fi,z=a[2].fi;
        if(x==y||y==z)exit(0);
        if(y*2==x+z)v=y-x;
        else v=2*z-y-x;
        printf("%lld\n",v);cout.flush();
        scanf("%lld",&x);if(!x)exit(0);
        for(int i=0;i<3;i++)if(a[i].se==x)a[i].fi+=v;
    }
    return 0;
}