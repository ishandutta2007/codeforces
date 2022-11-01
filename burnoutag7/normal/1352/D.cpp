#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int l=1,r=n,pa=0,pb=0,ta=0,tb=0,cur=1,tot=0;
        while(l<=r){
            tot++;
            if(cur){//alice
                pa=0;
                while(l<=r&&pa<=pb){
                    pa+=a[l++];
                }
                ta+=pa;
            }else{
                pb=0;
                while(l<=r&&pa>=pb){
                    pb+=a[r--];
                }
                tb+=pb;
            }
            cur^=1;
        }
        cout<<tot<<' '<<ta<<' '<<tb<<endl;
    }

    return 0;
}