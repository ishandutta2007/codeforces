#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int gcd(int a,int b){
	if (a%b==0) return b;
	return gcd(b,a%b);
}
map<int,short>inneed;
int n,a[300004];
int st[100004][17];
int pl[17],pt[100004],cnt=0;
map<int,ll>ans;
int query(int l,int r){
    int sz=pt[r-l+1];
    return gcd(st[l][sz],st[r-pl[sz]+1][sz]);
}
int find(int x,int l,int L){
    int r=n,anss=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(query(L,mid)!=x)r=mid-1;
        else anss=mid,l=mid+1;
    }
    return anss;
}
void solve(int x){
    int t=st[x][0],now=x;
    while(1){
        int last=now;
        now=find(t,now,x);
        if(inneed[t])ans[t]+=now-last+1;
        if(now==n)return;
        now++;t=query(x,now);
    }
}
int main(){
	pl[0]=1;for (int i=1;i<17;i++) pl[i]=pl[i-1]*2;
	for (int i=1;i<=100000;i++){
		if (pl[cnt+1]==i) cnt++;
		pt[i]=cnt;
	}
	read(n);
	for (int i=1;i<=n;i++)
		read(st[i][0]);
	for (int i=1;i<17;i++)
		for (int j=1;j<=n;j++) if (j+pl[i]-1<=n)
			st[j][i]=gcd(st[j][i-1],st[j+pl[i-1]][i-1]);
	int q;read(q);
	for (int i=1;i<=q;i++){
		read(a[i]);
		inneed[a[i]]=1;
	}
	for (int i=1;i<=n;i++) solve(i);
	for (int i=1;i<=q;i++) write(ans[a[i]]),puts("");
}