#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,b,a,x,y;
bool su[maxn];

int main(){
    cin>>n>>a>>b;
    x=a;y=b;
    for(int i=1;i<=n;i++)cin>>su[i];
    for(int i=1;i<=n;i++){
        if(su[i]){
            if(y==b){
                if(y==0){
                    x--;
                }else{
                    y--;
                }
            }else{
                if(x!=0){
                    x--;
                    y++;
                }else{
                    y--;
                }
            }
        }else{
            if(y==0){
                x--;
            }else{
                y--;
            }
        }
        if(x==0&&y==0){
            cout<<i;
            return 0;
        }
    }
    cout<<n;
    return 0;
}