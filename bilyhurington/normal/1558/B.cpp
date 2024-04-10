#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int n,mod;
int f[4000010],g[4000010];
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int del(int x,int y){return x>=y?x-y:x+mod-y;}
inline void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void Del(int &x,int y){x-=y;if(x<0) x+=mod;}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&mod);
    f[n]=g[n]=1;
    for(int i=n-1;i>=1;i--){
        g[i]=f[i]=g[i+1];
        for(int j=2;i*j<=n;j++){//f[i*j]~f[i*j+1]
            Add(f[i],del(g[i*j],g[min(n+1,i*j+j)]));
            // printf("%d %d\n",i*j,i*j+j-1);
        }
        Add(g[i],f[i]);
        // printf("%d %d\n",f[i],g[i]);
    }
    printf("%d",f[1]);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}