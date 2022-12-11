#include<bits/stdc++.h>
using namespace std;
int n,m,f[223456],s[223456]; char b[233333];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
    int _; cin>>_; while(_--){
		scanf("%d",&n);
        for(int i=1;i<=n+n;++i) f[i]=i;
        cin>>b+1;
        for(int i=1,d=0;i<=n+n;++i)
            if(b[i]=='('){
                if(b[i-1]==')') f[find(i-1)]=find(i);
                d++;
                s[d]=i;
            }else{
                f[find(i)]=find(s[d]);
                d--;
            }
        int ans=0;
        for(int i=1;i<=n+n;++i) ans+=find(i)==i;
        printf("%d\n",ans);
	}
}