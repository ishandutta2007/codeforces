#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=20000010;
int i,j,k,n,m,T,a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		int ans=1e9,chs=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)a[i]=b[i]=read();
		int num=(n+m+1)/2;
		sort(a+1,a+1+n);
		for(i=1;i<=n-num+1;i++){
			if(a[i+num-1]-a[i]<ans){
				ans=min(a[i+num-1]-a[i],ans);
				chs=i;
			}
		}
		printf("%d %d\n",a[chs],a[chs+num-1]);
		int Num=0,last=1,sum=0;
		for(i=1;i<=n;i++){
			if(b[i]<=a[chs+num-1] && b[i]>=a[chs])Num++;
			else Num--;
//			cerr<<i<<' '<<Num<<endl;
			if(Num>0){
				if(i!=n && sum==m-1)continue;
				sum++;
				printf("%d %d\n",last,i);
				last=i+1;
				Num=0;
			}
		}
	}
	return 0;
}