#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    string s;
    for(int i=0; i<q; i++){
        int n;
        cin >> n;
        int a[n*2];
        for(int j=0; j<n; j++){
            cin >> a[j];
            a[n+j]=a[j];
        }
        int c=0,t=0;
        for(int j=0; j<n*2; j++){
            if(c==a[j]-1){
                c++;
            }else if(c!=n) c=0;
            if(c==n){
                s+="YES\n";
                t=1;
                break;
            }
        }
        c=n+1;
        if(t==0){
            for(int j=0; j<n*2; j++){
                if(c==a[j]+1){
                    c--;
                }else if(c!=1) c=n+1;
                if(c==1){
                    s+="YES\n";
                    t=1;
                    break;
                }
            }
        }
        if(t==0) s+="NO\n";
    }
    cout << s;
    return 0;
}