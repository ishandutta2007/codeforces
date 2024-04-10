#include<bits/stdc++.h>

using namespace std;

const int maxn=200;

char x[maxn];
char y[maxn];
int n;



int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>(x+1);
        n=strlen(x+1);
        int o1=0,o2=0,o3=0;
        int c1=0,c2=0,c3=0;
        for(int i=1;i<=n;i++){
            if(x[i]>='0'&&x[i]<='9') o1=1,c1++;
            if(x[i]>='a'&&x[i]<='z') o2=1,c2++;
            if(x[i]>='A'&&x[i]<='Z') o3=1,c3++;
        }
        if(o1+o2+o3==3){
            cout<<(x+1)<<'\n';
        }else if(o1+o2+o3==1){
            char a='a',b='A';
            if(o2) a='1';
            if(o3) b='1';
            x[1]=a;
            x[2]=b;
            cout<<(x+1)<<'\n';
        }else{
            char a='1';
            if(!o2) a='a';
            if(!o3) a='A';
            for(int i=1;i<=n;i++){
                if(x[i]>='0'&&x[i]<='9'){
                    if(c1>1){
                        x[i]=a;
                        break;
                    }
                }
                if(x[i]>='a'&&x[i]<='z'){
                    if(c2>1){
                        x[i]=a;
                        break;
                    }
                }
                if(x[i]>='A'&&x[i]<='Z'){
                    if(c3>1){
                        x[i]=a;
                        break;
                    }
                }
            }
            cout<<(x+1)<<'\n';
        }
    }
    
    return 0;
}