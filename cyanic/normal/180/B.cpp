#include<cstdio>
int c2(int b,int d){return 1LL*b*b*b*b*b*b%d==0;}
int c3(int b,int d){return (b-1)%d==0;}
int c1(int b,int d){return (b+1)%d==0;}
int c6(int b,int d){int t=0,i=2;for(;i<=d;i++){t=1;while(d%i==0)d/=i,t*=i;
if(!c2(b,t)&&!c3(b,t)&&!c1(b,t))return 0;}return 1;}
int main(){int b,d,r=0,t=1;scanf("%d%d", &b, &d);
if(c2(b,d)){puts("2-type");while(t%d!=0)t*=b,r++;printf("%d\n",r);}
else if(c3(b,d))puts("3-type");
else if(c1(b,d))puts("11-type");
else if(c6(b,d))puts("6-type");
else puts("7-type");return 0;}