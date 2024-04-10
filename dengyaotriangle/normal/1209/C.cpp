#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;

int n;
char x[maxn];
int cl[maxn];

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>(x+1);
        bool gt=0;
        for(int i='0';i<='9';i++){
            int lsj=1;
            for(int j=1;j<=n;j++)cl[j]=2;
            for(int j=1;j<=n;j++){
                if(x[j]<i){
                    cl[j]=1;
                    lsj=j;
                }
            }
            for(int j=lsj;j<=n;j++)if(x[j]<=i)cl[j]=1;
            bool ok=1;
            int lp='0';
            for(int j=1;j<=n;j++){
                if(cl[j]==1){
                    if(x[j]>=lp)lp=x[j];
                    else ok=0;
                }
            }
            for(int j=1;j<=n;j++){
                if(cl[j]==2){
                    if(x[j]>=lp)lp=x[j];
                    else ok=0;
                }
            }
            
            if(ok){
                gt=1;
                break;
            }
        }
        if(!gt)cout<<"-\n";
        else{
            for(int i=1;i<=n;i++)cout<<cl[i];
            cout<<"\n";
        }
    }
    return 0;
}