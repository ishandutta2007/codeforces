#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf 1000000000000000000
#define int long long
using namespace std;
int read(){
    int x=0,fg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if (ch=='-')fg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*fg;
}
struct Seg{
    int l,r;
}a[200005],_a[200005];
bool cmp(Seg a,Seg b){
    if (a.l==b.l)return a.r>b.r;
    return a.l<b.l;
}
int t,n,m,pos[200005],l[200005];
int f[200005];
void qwq_1(){
    int _m=0,j=n,mn=2e9;
    for (int i=m;i>=1;i--){
        while(j>=1&&pos[j]>=a[i].l)mn=min(mn,pos[j]),j--;
        if (mn>a[i].r)_a[++_m]=a[i];
    }
    m=_m;
    for (int i=1;i<=m;i++)a[i]=_a[i];
    return;
}
void qwq_2(){
    int _m=0,mn=2e9;
    for (int i=m;i>=1;i--){
        if (a[i].r<mn)_a[++_m]=a[i];
        mn=min(mn,a[i].r);
    }
    m=_m;
    for (int i=1;i<=m;i++)a[i]=_a[i];
    return;
}
int lower(int x){
	int l=1,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[mid].r<x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
signed main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for (int i=1;i<=n;i++)pos[i]=read();
        for (int i=1;i<=m;i++)a[i].l=read(),a[i].r=read();
        sort(pos+1,pos+1+n);
        sort(a+1,a+1+m,cmp);
        qwq_1();
        sort(a+1,a+1+m,cmp);
        qwq_2();
	    sort(a+1,a+1+m,cmp);
	    for (int i=1;i<=n;i++)l[i]=lower(pos[i]);
	    l[n+1]=m;
	    for (int i=0;i<=m;i++)f[i]=inf;
	    f[0]=0;
	    for (int i=1;i<=n;i++){
	    	int minval;
	    	minval=f[l[i]];
	    	for (int j=l[i];j>l[i-1];j--)
	    		minval=min(minval,2*(pos[i]-a[j].r)+f[j-1]);
	    	for (int j=l[i]+1;j<=l[i+1];j++)f[j]=min(f[j],minval+a[j].l-pos[i]);
	    	minval=inf;
	    	for (int j=l[i];j>l[i-1];j--)
	    		minval=min(minval,(pos[i]-a[j].r)+f[j-1]);
	    	for (int j=l[i]+1;j<=l[i+1];j++)f[j]=min(f[j],minval+2*(a[j].l-pos[i]));
	    	minval=inf;
			for (int j=l[i];j>l[i-1];j--)
	    		minval=min(minval,f[j-1]+pos[i]-a[j].r);
	    	f[l[i]]=min(f[l[i]],minval);
		}
		cout<<f[m]<<endl;
    }
    return 0;
}