#include<bits/stdc++.h>
#define LL long long
#define ld long double
using namespace std;
const int N=1e4+50;
const ld pi=acos(-1.0);
int n,q,id,now;LL S;ld ci[N],len[N];
struct dpoi{
    ld x,y;
    dpoi operator +(const dpoi &b){return (dpoi){x+b.x,y+b.y};}
}b[N],Z;
struct poi{
    int x,y;
    poi operator -(const poi &b){return (poi){x-b.x,y-b.y};}
    poi operator +(const poi &b){return (poi){x+b.x,y+b.y};}
    LL operator *(const poi &b){return 1ll*x*b.y-1ll*y*b.x;}
    dpoi operator *(const ld &b){return (dpoi){x*b,y*b};}
}a[N];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=2;i<n;i++)S+=(a[i]-a[1])*(a[i+1]-a[1]);
    for(int i=2;i<n;i++)Z=Z+(a[i]+a[i+1]+a[1])*((a[i]-a[1])*(a[i+1]-a[1])/(3.0l*S));
    for(int i=1;i<=n;i++)
        ci[i]=atan2(a[i].y-Z.y,a[i].x-Z.x),
        len[i]=sqrt((a[i].y-Z.y)*(a[i].y-Z.y)+(a[i].x-Z.x)*(a[i].x-Z.x));
    b[1]=(dpoi){a[1].x,a[1].y};b[2]=(dpoi){a[2].x,a[2].y};now=1^2;
    for(int i=1,op,f,t;i<=q;i++){
        scanf("%d%d",&op,&f);
        if(op==1){
            scanf("%d",&t);id=now^f;now=id^t;
            b[t]=b[id]+(dpoi){0,-len[id]};
            b[t]=b[t]+(dpoi){len[t]*cos(ci[t]-ci[id]+pi/2),len[t]*sin(ci[t]-ci[id]+pi/2)};
        }
        else{
            if(!id)printf("%.9f %.9f\n",(double)a[f].x,(double)a[f].y);
            else{
                b[f]=b[id]+(dpoi){0,-len[id]};
                b[f]=b[f]+(dpoi){len[f]*cos(ci[f]-ci[id]+pi/2),len[f]*sin(ci[f]-ci[id]+pi/2)};
                printf("%.9f %.9f\n",(double)b[f].x,(double)b[f].y);
            }
        }
    }
    return 0;
}