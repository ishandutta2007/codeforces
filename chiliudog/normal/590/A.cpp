#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=500005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int s[maxn],n,res[maxn];
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
 //   judge();
	read(n);
	fortodo(i,1,n)read(s[i]);
	int ans=0;res[1]=s[1];res[n]=s[n];
	fortodo(i,2,n-1){
		if (s[i]==s[i+1]){
			res[i]=s[i];continue;
		}
		if (s[i]==s[i-1]){
			res[i]=s[i];continue;
		}
		int j=i+1;
		while(j<n&&s[j+1]!=s[j])j++;
		j--;ans=max(ans,(j-i+1+1)/2);
		if ((j-i+1)%2==0){
			fortodo(k,i,(i+j-1)/2)res[k]=s[i-1];
			fortodo(k,(i+j-1)/2+1,j)res[k]=s[j+1];
		}
		else{
			fortodo(k,i,j)res[k]=s[i-1];
		}
		i=j;
	}
	printf("%d\n",ans);
	fortodo(i,1,n)printf("%d ",res[i]);
    return 0;
}