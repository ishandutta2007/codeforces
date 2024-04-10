#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=100;
int arr[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    const int turns=n*n;
    int ct;
    int exp2=turns/2;
    int exp1=turns-exp2;
    for(ct=0;ct<turns&&exp1>0&&exp2>0;++ct){
        int a;
        cin>>a;
        if(a==1){
            for(int i=0;i<n;++i){
                int j;
                for(j=0;j<n;++j){
                    if((i+j)%2==1&&arr[i][j]==0){
                        arr[i][j]=2;
                        cout<<2<<' '<<i+1<<' '<<j+1<<endl;
                        --exp2;
                        break;
                    }
                }
                if(j<n)break;
            }
        }
        else{
            for(int i=0;i<n;++i){
                int j;
                for(j=0;j<n;++j){
                    if((i+j)%2==0&&arr[i][j]==0){
                        arr[i][j]=1;
                        cout<<1<<' '<<i+1<<' '<<j+1<<endl;
                        --exp1;
                        break;
                    }
                }
                if(j<n)break;
            }
        }
    }
    for(;ct<turns;++ct){
        int a;
        cin>>a;
        for(int i=0;i<n;++i){
            int j;
            for(j=0;j<n;++j){
                if(arr[i][j]==0){
                    int r=(exp1==0)?((a==2)?3:2):((a==1)?3:1);
                    arr[i][j]=r;
                    cout<<r<<' '<<i+1<<' '<<j+1<<endl;
                    break;
                }
            }
            if(j<n)break;
        }
    }
}