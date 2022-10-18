#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=10005;
int stk[maxn];
int sp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        sp=0;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(sp==0||a==1)stk[++sp]=1;
            else{
                while(stk[sp]+1!=a)sp--;
                stk[sp]++;
            }
            for(int j=1;j<=sp;j++){
                cout<<stk[j];
                if(j!=sp)cout<<'.';
            }
            cout<<'\n';
        }
    }
    return 0;
}