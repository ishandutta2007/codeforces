#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=200005;
int n,m;
ll ans;
int stmn[maxn][20],stmx[maxn][20];
int a[maxn],b[maxn];
int lg[maxn];
int ques(int l,int r,bool opt)
{
	int len=r-l+1;
	if(!opt) return min(stmn[l][lg[len]],stmn[r-(1<<(lg[len]))+1][lg[len]]);
	return max(stmx[l][lg[len]],stmx[r-(1<<(lg[len]))+1][lg[len]]);
}
int main() {
    cin>>n;
    int i,j;
    int tmp=0;
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(i>=(1<<(tmp+1))) tmp++;
        lg[i]=tmp;
    }
    for(i=1;i<=n;i++) scanf("%d",&b[i]);
    for(j=0;(1<<j)<=n;j++)
    {
        for(i=1;i+(1<<j)-1<=n;i++)
        {
            if(j==0) stmn[i][j]=b[i];
            else stmn[i][j]=min(stmn[i][j-1],stmn[i+(1<<j-1)][j-1]);
            if(j==0) stmx[i][j]=a[i];
            else stmx[i][j]=max(stmx[i][j-1],stmx[i+(1<<j-1)][j-1]);
        }
    }
    for(i=1;i<=n;i++)
    {
    	int l=i,r=n;
    	int lans,rans;
    	while(r-l>5) 
    	{
    		int mid=(l+r)/2;
    		if(ques(i,mid,0)>ques(i,mid,1)) l=mid;
    		else r=mid;
    	}
    	for(j=l;j<=r;j++) if(ques(i,j,1)==ques(i,j,0)) break;
    	if(j==r+1) continue;
    	else lans=j;
    	l=i;r=n;
    	while(r-l>5) 
    	{
    		int mid=(l+r)/2;
    		if(ques(i,mid,0)>=ques(i,mid,1)) l=mid;
    		else r=mid;
    	}
    	for(j=r;j>=l;j--) if(ques(i,j,1)==ques(i,j,0)) break;
    	if(j==l-1) continue;
    	else rans=j;
    	ans+=ll(rans-lans+1);
    }
    cout<<ans;
    return 0;
}