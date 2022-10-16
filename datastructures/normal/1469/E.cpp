#include <iostream>
#include <cstdio>
using namespace std;
int t,n,len,a[1000005],ans[1000005],book[1000005];
char s[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>len;
		scanf("%s",s+1);
		for (register int i=1;i<=n;i++)a[i]='1'-s[i];
		for (register int i=1;i<=n;i++){
			register int j=i;
			while(a[j]==0&&j<=n)j++;
			if (j-i>=len)book[0]=1;
			if (j>n)break;
			register int nowval=0;
			for (register int k=j;k<=n;k++){
				nowval=nowval*2+a[k];
				if (nowval>n)break;
				if (k-i+1>=len)book[nowval]=1;
			}
			i=j;
		}
		register int fg=0;
		for (register int i=0;i<=n;i++){
			if (len<=20&&i>=(1<<len))break;
			if (book[i]==0){
				fg=1;
				register int nowval=i,nowlen=len;
				while(nowval)ans[nowlen]=nowval%2,nowval/=2,nowlen--;
				break;
			}
		}
		if (fg==0)puts("NO");
		else{
			puts("YES");
			for (register int i=1;i<=len;i++)printf("%d",ans[i]);
			cout<<endl; 
		}
		for (register int i=0;i<=n;i++)book[i]=ans[i]=0;
	}
	return 0;
}