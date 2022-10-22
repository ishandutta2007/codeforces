#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
inline void read(int &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
inline void print(int x,char ch) {
	if(x<0){ putchar('-');x=-x;}
	if(x>9) print(x/10,'\0');putchar(x%10+'0');
	if(ch!='\0') putchar(ch);return;
}
int n,m;
bool a[maxn];
int pre[maxn],nxt[maxn];
int main()
{
	int i,j;
    read(n);
    for(i=1;i<=n;i++)
    {
        char ch=getchar();
        if(ch=='G') a[i]=1;
        else a[i]=0;
    }
    #ifdef TIME
        clock_t ST=clock();
    #endif
    int tmp=0,cnt=0;
    for(i=1;i<=n+1;i++)
    {
        if(a[i]==1) tmp++;
        if(a[i]==0&&a[i-1]==1) 
        {
            cnt++;
            pre[i]=tmp;
            tmp=0;
        }
    }
    tmp=0;
    for(i=n;i>=0;i--)
    {
        if(a[i]==1) tmp++;
        if(a[i]==0&&a[i+1]==1) 
        {
            nxt[i]=tmp;
            tmp=0;
        }
    }
    int mx=-1;
    for(i=0;i<=n+1;i++)
    {
        mx=max(mx,pre[i]+nxt[i]);
        if(cnt>=2&&pre[i]==0) mx=max(mx,nxt[i]+1);
        if(cnt>=2&&nxt[i]==0) mx=max(mx,pre[i]+1);
        if(cnt>2) mx=max(mx,pre[i]+nxt[i]+1);
    }
    print(mx,'\0');
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	return 0;
}