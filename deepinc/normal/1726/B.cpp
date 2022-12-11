#include<bits/stdc++.h>
using namespace std;
int n,m,a[233333];
int main(){
    int _; cin>>_; while(_--){
		scanf("%d%d",&n,&m);
        if(n==1) puts("YES"),printf("%d\n",m);
        else if(m<n) puts("NO");
        else if(m%n==0){
            puts("YES");
            for(int i=1;i<=n;++i)printf("%d ",m/n);
            puts("");
        }else if(n%2==1){
            puts("YES");
            for(int i=1;i<n;++i)printf("1 ");
            printf("%d\n",m-n+1);
        }else if(m%2==0){
            puts("YES");
            for(int i=1;i<=n-2;++i)printf("1 ");
            printf("%d %d\n",(m-n+2)/2,(m-n+2)/2);
        }else puts("NO");
	}
}