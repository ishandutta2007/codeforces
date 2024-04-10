#include<bits/stdc++.h>
const int N=1e5+3;
int n,a[N],b[N],fl;
int main(){
	int T;scanf("%d",&T);for(;T--;){
		scanf("%d",&n);
		fl=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			b[a[i]]+=i&1;
		}
		std::sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)b[a[i]]-=i&1;
		for(int i=1;i<=n;i++)
			if(b[a[i]]){
				fl=1;
				b[a[i]]=0;
			}
		puts(fl?"NO":"YES");
	}
	return 0;
}