#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,f0=0,f5=0,fo=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]%10==0) f0=1;
            else if(a[i]%10==5) f5=1;
            else fo=1;
        }
        if(fo){
            if(!f0&&!f5){
                int t[2]={};
                for(int i=1;i<=n;i++){
                    if(a[i]%10==1||a[i]%10==2||a[i]%10==4||a[i]%10==8){
                        int temp=a[i]/10;
                        t[(temp+1)%2]=1;
                    }
                    else{
                        int temp=a[i]/10;
                        t[temp%2]=1;
                    }
                }
                if(t[0]&&t[1]) puts("No");
                else puts("Yes");
            }
            else puts("No");
        }
        else{
            if(f0&&f5){
                int v0=-1,v5=-1,f=1;
                for(int i=1;i<=n;i++){
                    if(a[i]%10==0){
                        if(v0==-1) v0=a[i];
                        else{
                            if(v0!=a[i]) f=0;
                        }
                    }
                    else{
                        if(v5==-1) v5=a[i];
                        else{
                            if(v5!=a[i]) f=0;
                        }
                    }
                }
                puts(f&&v0==v5+5?"Yes":"No");
            }
            else if(f0){
                int v0=-1,v5=-1,f=1;
                for(int i=1;i<=n;i++){
                    if(a[i]%10==0){
                        if(v0==-1) v0=a[i];
                        else{
                            if(v0!=a[i]) f=0;
                        }
                    }
                    else{
                        if(v5==-1) v5=a[i];
                        else{
                            if(v5!=a[i]) f=0;
                        }
                    }
                }
                puts(f?"Yes":"No");
            }
            else{
                int v0=-1,v5=-1,f=1;
                for(int i=1;i<=n;i++){
                    if(a[i]%10==0){
                        if(v0==-1) v0=a[i];
                        else{
                            if(v0!=a[i]) f=0;
                        }
                    }
                    else{
                        if(v5==-1) v5=a[i];
                        else{
                            if(v5!=a[i]) f=0;
                        }
                    }
                }
                puts(f?"Yes":"No");
            }
        }
    }
    return 0;
}