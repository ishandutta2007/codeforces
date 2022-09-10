#include<bits/stdc++.h>
using namespace std;
int AA[128];
int n;
bool u[10001];
void answer(int x,int y){
    printf("%d %d\n",x,y);
 
}
void solve(){
    u[AA[n-1]]=1;
    for(int i=n-2;i>=0;i--){
        if(AA[n-1]%AA[i]==0){
            if(u[AA[i]]){
                answer(AA[n-1],AA[i]);
                return;
            }
            u[AA[i]]=1;
        }
        else{
            answer(AA[n-1],AA[i]);
            return;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&AA[i]);
    std::sort(AA,AA+n);
    solve();
    return 0;
}